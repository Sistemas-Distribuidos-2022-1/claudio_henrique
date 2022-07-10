#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BACK_LOG 10

int salary_readjustment(char *message, char *response){
    int msg_size = 0;
    char *name = strtok(message, ";");
    char *office = strtok(NULL, ";");
    float salary = atof(strtok(NULL, ";"));

    if(office[0] == 'o')    salary *= 1.20;
    if(office[0] == 'p')    salary *= 1.18;

    msg_size = sprintf(response, "O %s %s agora recebe %.2f reais.", office, name, salary);

    return msg_size;
}

int majority(char *message, char *response){
    int msg_size = 0;
    char *name = strtok(message, ";");
    char *sex = strtok(NULL, ";");
    int age = atoi(strtok(NULL, ";"));

    if((sex[0] == 'M' && age >= 18) && (sex[0] == 'F' && age >= 21))   msg_size = sprintf(response, "%s já atingiu a maioridade.", name);
    else    msg_size = sprintf(response, "%s ainda é menor de idade.", name);

    return msg_size;
}

int college_average(char *message, char *response){
    int msg_size = 0;
    float n1 = atof(strtok(message, ";")), n2 = atof(strtok(NULL, ";")), n3 = atof(strtok(NULL, ";"));

    float md = (n1+n2)/2;
    float mdf = (md+n3)/2;

    if(md >= 7) msg_size = sprintf(response, "Aprovado");
    else
        if(md > 3)
            if(mdf>=5)  msg_size = sprintf(response, "Aprovado");
            else    msg_size = sprintf(response, "Reprovado");
        else    msg_size = sprintf(response, "Reprovado");

    return msg_size;
}

int ideal_weight(char *message, char *response){
    int msg_size = 0;
    char *sex = strtok(message, ";");
    float height = atof(strtok(NULL, ";"));
    float weight = 0;

    if(sex[0] == 'M')   weight = (72.7 * height) - 58;
    else    weight = (62.1 * height) - 44.7;
    
    msg_size = sprintf(response, "O peso ideal é de %.2f.", height);

    return msg_size;
}

int swimmer_classification(char *message, char *response){
    int msg_size = 0;
    int age = atoi(message);

    if(age < 5) msg_size = sprintf(response, "Não se aplica");
    else
        if(age <= 7)    msg_size = sprintf(response, "Infantil A");
        else
            if(age <= 10)   msg_size = sprintf(response, "Infantil B");
            else
                if(age <= 13)   msg_size = sprintf(response, "Juvenil A");
                else
                    if(age <= 17)   msg_size = sprintf(response, "Juvenil B");
                    else    msg_size = sprintf(response, "Adulto");

    return msg_size;
}

int net_salary(char *message, char *response){
    int msg_size = 0;
    char *name = strtok(message, ";");
    char *level = strtok(NULL, ";");
    float salary = atof(strtok(NULL, ";"));
    int dependents = atoi(strtok(NULL, ";"));

    if((*level) == 'A')
        if(dependents != 0) salary *= 0.92;
        else  salary *= 0.97;
    if((*level) == 'B')
        if(dependents != 0) salary *= 0.9;
        else  salary *= 0.95;
    if((*level) == 'C')
        if(dependents != 0) salary *= 0.85;
        else  salary *= 0.92;
    if((*level) == 'D')
        if(dependents != 0) salary *= 0.83;
        else  salary *= 0.9;

    msg_size = sprintf(response, "O salario liquido de %s é de %.2f reais.", name, salary);

    return msg_size;
}

int retirement(char *message, char *response){
    int msg_size = 0;
    int age = atoi(strtok(message, ";"));
    int years_worked = atoi(strtok(NULL, ";"));

    if(age >= 65 && years_worked >= 30) msg_size = sprintf(response, "Já pode se aposentar.");
    else    msg_size = sprintf(response, "Ainda não pode se aposentar");

    return msg_size;
}

int special_credit(char *message, char *response){
    int msg_size = 0;
    float average_balance = atof(message);

    if(average_balance <= 200)   msg_size = sprintf(response, "Saldo medio: %.2f\nNenhum credito concedido.", average_balance);
    else
        if(average_balance <= 400)    msg_size = sprintf(response, "Saldo medio: %.2f\nConcedido 20%% do saldo medio.\nValor do credito: %.2f", average_balance, average_balance*0.2);
        else
            if(average_balance <= 600)   msg_size = sprintf(response, "Saldo medio: %.2f\nConcedido 30%% do saldo medio.\nValor do credito: %.2f", average_balance, average_balance*0.3);
            else    msg_size = sprintf(response, "Saldo medio: %.2f\nConcedido 40%% do saldo medio.\nValor do credito: %.2f", average_balance, average_balance*0.4);

    return msg_size;
}

int card_name(char *message, char *response){
    int msg_size = 0;
    int card_number = atoi(strtok(message, ";"));
    int card_suit = atoi(strtok(NULL, ";"));
    char numero[7];
    char  naipe[8];

    if(card_number == 1)    sprintf(numero, "as");
    if(card_number == 2)    sprintf(numero, "dois");
    if(card_number == 3)    sprintf(numero, "tres");
    if(card_number == 4)    sprintf(numero, "quatro");
    if(card_number == 5)    sprintf(numero, "cinco");
    if(card_number == 6)    sprintf(numero, "seis");
    if(card_number == 7)    sprintf(numero, "sete");
    if(card_number == 8)    sprintf(numero, "oito");
    if(card_number == 9)    sprintf(numero, "nove");
    if(card_number == 10)    sprintf(numero, "dez");
    if(card_number == 11)    sprintf(numero, "valete");
    if(card_number == 12)    sprintf(numero, "dama");
    if(card_number == 13)    sprintf(numero, "rei");

    if(card_suit == 1)    sprintf(naipe, "ouros");
    if(card_suit == 2)    sprintf(naipe, "paus");
    if(card_suit == 3)    sprintf(naipe, "copas");
    if(card_suit == 4)    sprintf(naipe, "espadas");

    msg_size = sprintf(response, "A carta é %s de %s", numero, naipe);

    return msg_size;
}

int decode_message(char *message, char *response){
    char quest = message[0];

    switch(quest){
        case 'A':
            salary_readjustment(&message[2], response);
            break;
        case 'B':
            majority(&message[2], response);
            break;
        case 'C':
            college_average(&message[2], response);
            break;
        case 'D':
            ideal_weight(&message[2], response);
            break;
        case 'E':
            swimmer_classification(&message[2], response);
            break;
        case 'F':
            net_salary(&message[2], response);
            break;
        case 'G':
            retirement(&message[2], response);
            break;
        case 'H':
            special_credit(&message[2], response);
            break;
        case 'I':
            card_name(&message[2], response);
            break;
    }
}

int main(int argc, char const* argv[]){
    int listenfd,connectfd;
    struct sockaddr_in server;
    struct sockaddr_in client;
    pid_t childpid;
    socklen_t addrlen;
    char buff[4096];
    char response[1024] = { 0 };
    int response_size = 0;

    listenfd = socket(AF_INET,SOCK_STREAM,0);
    if(listenfd == -1){
        perror("socker created failed");
        exit(0);
    }

    int option;
    option = SO_REUSEADDR;
    setsockopt(listenfd,SOL_SOCKET,option,&option,sizeof(option));
    bzero(&server,sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(listenfd,(struct sockaddr *)&server,sizeof(server)) == -1){
        perror("Bind error!");
        exit(1);
    }
    if(listen(listenfd,BACK_LOG) == -1){
        perror("listend error");
        exit(1);
    }

    printf("waiting for client's request.....\n");
    while(1){
        int n;
        addrlen = sizeof(client);
        connectfd = accept(listenfd,(struct sockaddr*)&client,&addrlen);
        if(connectfd == -1){
            perror("accept error");
            exit(0);
        }else{
            printf("client connected\n");
        }
        if((childpid = fork()) == 0){	
            close(listenfd);
            printf("client from %s\n",inet_ntoa(client.sin_addr));
            
            printf("ready to read\n");
            while((n = read(connectfd,buff,4096)) > 0){
                buff[n] = '\0';
                printf("recv msg from client: %s\n",buff);
                response_size = decode_message(buff, response);
                
                send(connectfd, response, response_size, 0);
            }
            printf("end read\n");
            exit(0);
        }else if(childpid < 0)
            printf("fork error: %s\n",strerror(errno));

        close(connectfd);
	}
    return 0;
}