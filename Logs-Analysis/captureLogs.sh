#!/usr/bin/env bash
# shellcheck shell=bash
# Usage: ./logs.sh -l app=app or ./logs.sh -l app=app -a combinedapplog.txt or 
# Author: nataz77 (https://github.com/nataz77)

function printusage {
    echo 'Log extractor';
    echo 'eg: ./logs.sh -l app=app ';
    echo 'eg: ./logs.sh -l app=app -n app ';
    echo "eg: ./logs.sh -l app=app -a log.txt"
    echo "eg: ./logs.sh -l app=app -n app -a log.txt"
    exit 1;
}

if [ -z "$*" ]; then echo "No arguments specified"; printusage; fi

while getopts "l:a:n:" opt
do
    case "${opt}" in
        l) LABEL=${OPTARG};;
        a) OUTPUT=${OPTARG};;
        n) NAMESPACE=${OPTARG};;
        *) printusage
    esac
done

# let's assume default if no other namespace is specified
if [ -z "$NAMESPACE" ]
then
  NAMESPACE=default
fi

PODS=$(kubectl get pods -n "$NAMESPACE" -l "$LABEL" -o go-template --template '{{range .items}}{{.metadata.name}}{{"\n"}}{{end}}')
if [ -z "$PODS" ]; then echo "No pods matched label $LABEL in namespace $NAMESPACE"; exit 2; fi

for pod in $PODS
do
    #depending on logs, this may take a while
    echo "Getting logs from pod $pod in namespace $NAMESPACE, this may take a while..."
    if [ -z "$OUTPUT" ]
    then
      kubectl logs "$pod" > "$pod".txt
    else
      # usually it's not ideal to combine pod logs in a single file, but I found it helpful sometimes when you're looking for a specific error and there's no correlationid or machineid with the pod hostname that generated id
      kubectl logs "$pod" >> "$OUTPUT".txt
    fi
    echo "Done"
done
