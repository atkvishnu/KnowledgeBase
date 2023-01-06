# How to create public and private key with openssl? 

How to put the created public key in .crt file and the private one in .pcks8 file in order to use this two keys to sign a SAML assertion in Java?

- A certificate (what you usually store in a .crt file) contains a public key, but a public key in itself is not a certificate.



- You can generate a public-private keypair with the genrsa context (the last number is the keylength in bits):

```
openssl genrsa -out keypair.pem 2048
```

To extract the public part, use the rsa context:

```
openssl rsa -in keypair.pem -pubout -out publickey.crt
```

Finally, convert the original keypair to PKCS#8 format with the pkcs8 context:

```
openssl pkcs8 -topk8 -inform PEM -outform PEM -nocrypt -in keypair.pem -out pkcs8.key
```





