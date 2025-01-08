#!/bin/bash

DIR=$1
FILE=$2
CMD=$2
MAX_RETRIES=5
RETRY_DELAY=2  # Aguardar 2 segundos entre as tentativas

if [ "$DIR" = "1" ]; then
    DIR="mlx/man/man1"
elif [ "$DIR" = "3" ]; then
    DIR="mlx/man/man3"
fi

# Função para verificar se o arquivo está sendo usado
check_file_in_use() {
    lsof "$DIR/$FILE" &>/dev/null
    return $?
}

# Tentar executar o comando até MAX_RETRIES
attempt_command() {
    local attempts=0
    while [ $attempts -lt $MAX_RETRIES ]; do
        check_file_in_use
        if [ $? -eq 0 ]; then
            echo "Arquivo $DIR/$FILE está em uso por outro processo. Tentando novamente em $RETRY_DELAY segundos..."
            sleep $RETRY_DELAY
            ((attempts++))
        else
            # Se o arquivo não estiver em uso, executar o comando
            return 0
        fi
    done
    echo "Falha: O arquivo $DIR/$FILE está ocupado por outro processo após $MAX_RETRIES tentativas."
    return 1
}

# Executar o comando de acordo com a opção
if [ "$CMD" = "ls" ]; then
    ls "$DIR"
elif [ "$CMD" = "cat" ]; then
    FILE=$3
    attempt_command && cat "$DIR/$FILE"
else
    attempt_command && man -l "./$DIR/$FILE"
fi

