# If you come from bash you might have to change your $PATH.
export PATH=$HOME/bin:/usr/local/bin:$PATH

# Path to your oh-my-zsh installation.
export ZSH="$HOME/.oh-my-zsh"

# Set name of the theme to load --- if set to "random", it will
# load a random theme each time oh-my-zsh is loaded, in which case,
# to know which specific one was loaded, run: echo $RANDOM_THEME
# See https://github.com/ohmyzsh/ohmyzsh/wiki/Themes
# ZSH_THEME=""

# Set list of themes to pick from when loading at random
# Setting this variable when ZSH_THEME=random will cause zsh to load
# a theme from this variable instead of looking in $ZSH/themes/
# If set to an empty array, this variable will have no effect.
# ZSH_THEME_RANDOM_CANDIDATES=( "robbyrussell" "agnoster" )

# Uncomment the following line to use case-sensitive completion.
# CASE_SENSITIVE="true"

# Uncomment the following line to use hyphen-insensitive completion.
# Case-sensitive completion must be off. _ and - will be interchangeable.
# HYPHEN_INSENSITIVE="true"

# Uncomment one of the following lines to change the auto-update behavior
# zstyle ':omz:update' mode disabled  # disable automatic updates
# zstyle ':omz:update' mode auto      # update automatically without asking
# zstyle ':omz:update' mode reminder  # just remind me to update when it's time

# Uncomment the following line to change how often to auto-update (in days).
# zstyle ':omz:update' frequency 13

# Uncomment the following line if pasting URLs and other text is messed up.
# DISABLE_MAGIC_FUNCTIONS="true"

# Uncomment the following line to disable colors in ls.
# DISABLE_LS_COLORS="true"

# Uncomment the following line to disable auto-setting terminal title.
# DISABLE_AUTO_TITLE="true"

# Uncomment the following line to enable command auto-correction.
# ENABLE_CORRECTION="true"

# Uncomment the following line to display red dots whilst waiting for completion.
# You can also set it to another string to have that shown instead of the default red dots.
# e.g. COMPLETION_WAITING_DOTS="%F{yellow}waiting...%f"
# Caution: this setting can cause issues with multiline prompts in zsh < 5.7.1 (see #5765)
# COMPLETION_WAITING_DOTS="true"

# Uncomment the following line if you want to disable marking untracked files
# under VCS as dirty. This makes repository status check for large repositories
# much, much faster.
# DISABLE_UNTRACKED_FILES_DIRTY="true"

# Uncomment the following line if you want to change the command execution time
# stamp shown in the history command output.
# You can set one of the optional three formats:
# "mm/dd/yyyy"|"dd.mm.yyyy"|"yyyy-mm-dd"
# or set a custom format using the strftime function format specifications,
# see 'man strftime' for details.
# HIST_STAMPS="mm/dd/yyyy"

# Would you like to use another custom folder than $ZSH/custom?
# ZSH_CUSTOM=/path/to/new-custom-folder

# Which plugins would you like to load?
# Standard plugins can be found in $ZSH/plugins/
# Custom plugins may be added to $ZSH_CUSTOM/plugins/
# Example format: plugins=(rails git textmate ruby lighthouse)
# Add wisely, as too many plugins slow down shell startup.

source $ZSH/plugins

plugins=(git web-search dirhistory zsh-autosuggestions history)

source $ZSH/oh-my-zsh.sh


ZSH_THEME=""

# User configuration

export MANPATH="/usr/local/man:$MANPATH"

export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH
export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig:$PKG_CONFIG_PATH

# You may need to manually set your language environment
# export LANG=en_US.UTF-8

# Preferred editor for local and remote sessions
# if [[ -n $SSH_CONNECTION ]]; then
#   export EDITOR='vim'
# else
#   export EDITOR='mvim'
# fi

# Compilation flags
# export ARCHFLAGS="-arch x86_64"

# Set personal aliases, overriding those provided by oh-my-zsh libs,
# plugins, and themes. Aliases can be placed here, though oh-my-zsh
# users are encouraged to define aliases within the ZSH_CUSTOM folder.
# For a full list of active aliases, run `alias`.
#
# Example aliases
# alias zshconfig="mate ~/.zshrc"
# alias ohmyzsh="mate ~/.oh-my-zsh"


function logiqclean {
        echo "cleaning docker volumes"
        docker volume prune
        echo "Cleaning local dirs"
        cd /home/tito/.data
        for file in $(ls);do rm -rf $file ;echo "cleared $(pwd)";done
        cd /home/tito/tools/prometheus-2.35.0.linux-amd64
        rm -rf data/
        echo "Cleaning all docker images"
        docker rm -f $(docker ps -aq)
        echo "Creating all docker images"
        echo "Starting docker containers"
        echo "Creating minio bucket"
        dependencies
}

export REDIS_HOST=localhost
export POSTGRES_HOST=localhost
export JWE_AUTH_COOKIE_PRIVATE_KEY=/home/tito/projects/redash-fork/local_setup/sharedcerts/tls.key
export JWE_AUTH_COOKIE_PUBLIC_KEY=/home/tito/projects/redash-fork/local_setup/sharedcerts/tls.crt

alias credis='docker create --name fredis -p 6379:6379 redis'
alias cdb='docker create --name fdb -p 5432:5432 -e POSTGRES_PASSWORD=postgres -e POSTGRES_USERNAME=postgres postgres'
alias cminio='docker create --name fminio \
  -p 9000:9000 \
  -p 9001:9001 \
  -e "MINIO_ROOT_USER=minioadmin" \
  -e "MINIO_ROOT_PASSWORD=minioadmin" \
  minio/minio server /data --console-address ":9001"'

alias fdb='docker start fdb'
alias fredis='docker start fredis'
alias fminio='docker start fminio'
#alias pgrun='docker run --name postgres -p 5432:5432 -e POSTGRES_PASSWORD=postgres --network build-net-logiq -v postgres:/var/lib/postgresql/data -d postgres:13'
#alias pgrun='docker start 44a89bb5fdd7'

alias k='kubectl'
alias lflow='oci ce cluster create-kubeconfig --cluster-id ocid1.cluster.oc1.us-sanjose-1.aaaaaaaa6bbtvez5yqperf7aty5waqiow55wwiksoem77gt6sc6oplwypkda --file $HOME/.kube/config --region us-sanjose-1 --token-version 2.0.0  --kube-endpoint PUBLIC_ENDPOINT'
alias cdev="oci ce cluster create-kubeconfig --cluster-id ocid1.cluster.oc1.ap-mumbai-1.aaaaaaaa7ykfcj2wazzs7cgxpgernoykotdnso2kmzkm5rkujcn6xgtlhrga --file $HOME/.kube/config --region ap-mumbai-1 --token-version 2.0.0  --kube-endpoint PUBLIC_ENDPOINT"


function dependencies {
        credis
        cdb
        cminio
        fredis
        fdb
        fminio
        #pgrun
}


alias flash='cdbe && go build -tags "sqlite_vtable sqlite_json" && ./flash --config examples/configs/tito/config-free-tito.yaml --runtime_folder=/home/tito/.data --load-from-file=true -pg_max_open_Conns 50 -postgres_timeout 20s --all -disable-auth-interceptor -prometheus-host http://localhost:9090 -event_rule_path=/config --localhost=true'
alias cel='cdfe && source env/bin/activate && QUERY_REPORTING_HOST=localhost bin/run celery worker --app=redash.worker --beat -Qscheduled_queries,queries,celery -c1 #starts celery task manager'
alias ser='cdfe && source env/bin/activate && QUERY_REPORTING_HOST=localhost bin/run ./manage.py runserver --debugger --reload --host 0.0.0.0'

alias serve='cdfe && npm start'

alias prom='cd /home/tito/tools/prometheus-2.35.0.linux-amd64 && ./prometheus --config.file=/home/tito/tools/prometheus.yml'

export NVM_DIR="$HOME/.nvm"
[ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh"  # This loads nvm
[ -s "$NVM_DIR/bash_completion" ] && \. "$NVM_DIR/bash_completion"  # This loads nvm bash_completion
export PATH=/home/tito/bin:$PATH

[[ -e "/home/tito/lib/oracle-cli/lib/python3.10/site-packages/oci_cli/bin/oci_autocomplete.sh" ]] && source "/home/tito/lib/oracle-cli/lib/python3.10/site-packages/oci_cli/bin/oci_autocomplete.sh"
source /opt/docker-diff/docker-diff-completion
source /opt/docker-diff/docker-diff-completion


alias '?'=ddg
alias '??'=google
alias '???'=bing

alias clear='printf "\e[H\e[2J"'
alias cl='printf "\e[H\e[2J"'
alias c='printf "\e[H\e[2J"'

alias cat='batcat'
alias l='exa'
alias la='exa -a'
alias ls='exa --color=auto'
alias ll='exa -lah'
alias tree='tree -Csuh'
alias grep='rg'

alias mkcd='_mkcd(){ mkdir "$1"; cd "$1";}; _mkcd'

#---------------------------------------------------------------
# Git aliases
#alias gss='git stash show -p'

#---------------------------------------------------------------
# Helm

alias helmup='helm repo update && helm upgrade logiq -n logiq --set global.persistence.storageClass=microk8s-hostpath logiq-repo/logiq -f  ~/.kube/values.microk8s.yaml'
alias helmlogchanges='microk8s kubectl -n logiq edit sts logiq-flash -nlogiq # add -disable-auth-interceptor in args'

# rlwrap -z 'paint_prompt lemon_chiffon--pale_turquoise'
alias kcli="rlwrap kubectl-repl"
alias kc='kubectx'
alias kns='kubens'

#----------------------------brew------------------------------

eval $(/home/linuxbrew/.linuxbrew/bin/brew shellenv)


#---------------------------------------------------------------
# Cow-spoken fortunes every time you open the terminal

#function cowsayfortune {
#    NUMOFCOWS=`cowsay -l | tail -n +2 | wc -w`
#    WHICHCOW=$((RANDOM%$NUMOFCOWS+1))
#    THISCOW=`cowsay -l | tail -n +2 | sed -e 's/\ /\'$'\n/g' | sed $WHICHCOW'q;d'`
#
#    #echo "Selected cow: ${THISCOW}, from ${WHICHCOW}"
#    fortune | cowsay -f $THISCOW -W 100 | lolcat
#}

#alias rand='cowsayfortune'

#figlet -f Slant "Hello, World!" | lolcat

#-------------------------------------------------------------

alias btc='bluetoothctl connect 00:1E:7C:95:32:2E'
alias btd='bluetoothctl disconnect 00:1E:7C:95:32:2E'

alias opn='nautilus -s .'

alias cdkb='cd /home/tito/Documents/KnowledgeBase'
alias cdfe='cd /home/tito/projects/redash-fork'
alias cdbe='cd /home/tito/go/src/bitbucket.org/logiqcloud/flash'
alias cdlog='cd /home/tito/go/src/bitbucket.org/logiqcloud/flash-test-framework/'

#-------------------------------------------------------------
# PURE manual install, changing to zinit
#fpath+=('/home/tito/.nvm/versions/node/v14.19.1/lib/node_modules/pure-prompt/functions')

#autoload -U promptinit; promptinit

# change the path color
# zstyle :prompt:pure:path color white

# change the color for both `prompt:success` and `prompt:error`
#zstyle ':prompt:pure:prompt:*' color cyan

# turn on git stash status
#zstyle :prompt:pure:git:stash show yes

#prompt pure
#PROMPT='%(?.%F{magenta}△.%F{red}▲)%f '
#prompt_newline='%666v'

#-------------------------------------------------------------
export GOPRIVATE=bitbucket.org/logiqcloud/*



### Added by Zinit's installer
if [[ ! -f $HOME/.local/share/zinit/zinit.git/zinit.zsh ]]; then
    print -P "%F{33} %F{220}Installing %F{33}ZDHARMA-CONTINUUM%F{220} Initiative Plugin Manager (%F{33}zdharma-continuum/zinit%F{220})…%f"
    command mkdir -p "$HOME/.local/share/zinit" && command chmod g-rwX "$HOME/.local/share/zinit"
    command git clone https://github.com/zdharma-continuum/zinit "$HOME/.local/share/zinit/zinit.git" && \
        print -P "%F{33} %F{34}Installation successful.%f%b" || \
        print -P "%F{160} The clone has failed.%f%b"
fi

source "$HOME/.local/share/zinit/zinit.git/zinit.zsh"
autoload -Uz _zinit
(( ${+_comps} )) && _comps[zinit]=_zinit

# Load a few important annexes, without Turbo
# (this is currently required for annexes)
zinit light-mode for \
    zdharma-continuum/zinit-annex-as-monitor \
    zdharma-continuum/zinit-annex-bin-gem-node \
    zdharma-continuum/zinit-annex-patch-dl \
    zdharma-continuum/zinit-annex-rust

### End of Zinit's installer chunk


zinit ice compile'(pure|async).zsh' pick'async.zsh' src'pure.zsh'
zinit light sindresorhus/pure


source /home/tito/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh

[[ $commands[kubectl] ]] && source <(kubectl completion zsh)
