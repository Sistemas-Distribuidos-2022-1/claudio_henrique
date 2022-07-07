// Server side C/C++ program to demonstrate Socket
// programming
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8080

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
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = { 0 };
    char response[1024] = { 0 };
    int response_size = 0;
    char* hello = "Hello from server";
  
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
  
    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
  
    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    valread = read(new_socket, buffer, 1024);
    
    response_size = decode_message(buffer, response);

    send(new_socket, response, response_size, 0);
    
    
    // closing the connected socket
    close(new_socket);
    // closing the listening socket
    shutdown(server_fd, SHUT_RDWR);
    return 0;
}
