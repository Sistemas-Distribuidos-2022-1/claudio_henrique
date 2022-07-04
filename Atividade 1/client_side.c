#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define STR_LEN 100
#define PORT 8080

int send_message(char *message, int msg_size){

    printf("\n\n%s\n\n", message);
    
    int sock = 0, valread, client_fd;
    struct sockaddr_in serv_addr;
    char buffer[1024] = { 0 };

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Erro ao criar o Socket \n");
        return -1;
    }
  
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
  
    // Converte endereco IPv4 e IPv6 para texto binario
    // form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0 ) {
        printf("\nEndereco IP invalido/ Endereco nao suportado \n");
        return -1;
    }
  
    if ((client_fd = connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr))) < 0) {
        printf("\nFalha na conexao \n");
        return -1;
    }
    //envio da mensagem para o server
    send(sock, message, msg_size, 0);
    
    valread = read(sock, buffer, 1024);
    printf("%s\n", buffer);
  
    // encerra socket de conexao
    close(client_fd);
    return 0;
}

void salary_readjustment(){
    char message[STR_LEN];
    int msg_size = 0;
    char name[STR_LEN];
    char office[STR_LEN];
    float salary;

    printf("Entre com o Nome do Funcionario.: ");
    scanf("%[^\n]s", name);
    getchar();

    printf("Entre com o Cargo do Funcionario.: ");
    scanf("%[^\n]s", office);
    getchar();

    printf("Entre com o Salario do Funcionario(Formato 00.00).: ");
    scanf("%f", &salary);

    msg_size = sprintf(message, "A;%s;%s;%.2f", name, office, salary);

    send_message(message, msg_size);
}

void majority(){
    char message[STR_LEN];
    int msg_size = 0;
    char name[STR_LEN];
    char sex;
    int age;

    printf("Entre com o Nome da pessoa.: ");
    scanf("%[^\n]s", name);
    getchar();

    printf("Entre com o Sexo da pessoa(M ou F).: ");
    scanf("%c", &sex);
    getchar();

    printf("Entre com a idade da pessoa.: ");
    scanf("%d", &age);

    msg_size = sprintf(message, "B;%s;%c;%d", name, sex, age);

    send_message(message, msg_size);
}

void college_average(){
    char message[STR_LEN];
    int msg_size = 0;
    float n1, n2, n3;

    printf("Entre com a primeira nota.: ");
    scanf("%f", &n1);

    printf("Entre com a segunda nota.: ");
    scanf("%f", &n2);

    printf("Entre com a terceira nota.: ");
    scanf("%f", &n3);

    msg_size = sprintf(message, "C;%.2f;%.2f;%.2f", n1, n2, n3);

    send_message(message, msg_size);
}

void ideal_weight(){
    char message[STR_LEN];
    int msg_size = 0;
    float height;
    char sex;

    printf("Entre com o sexo da pessoa.: ");
    scanf("%c", &sex);
    getchar();

    printf("Entre com o peso da pessoa.: ");
    scanf("%f", &height);

    msg_size = sprintf(message, "D;%c;%.2f", sex, height);

    send_message(message, msg_size);
}

void swimmer_classification(){
    char message[STR_LEN];
    int msg_size = 0;
    int age;

    printf("Entre com a idade do nadador.: ");
    scanf("%d", &age);

    msg_size = sprintf(message, "E;%d", age);

    send_message(message, msg_size);
}

void net_salary(){
    char message[STR_LEN];
    int msg_size = 0;
    char name[STR_LEN];
    char level;
    float salary;
    int dependents = 0;

    printf("Entre com o Nome do Funcionario.: ");
    scanf("%[^\n]s", name);
    getchar();

    printf("Entre com o Nivel do Funcionario.: ");
    scanf("%c", &level);
    getchar();

    printf("Entre com o Salario Bruto do Funcionario(Formato 00.00).: ");
    scanf("%f", &salary);

    printf("Entre com a quantidade de dependentes do Funcionario.: ");
    scanf("%d", &dependents);

    msg_size = sprintf(message, "F;%s;%c;%.2f;%d", name, level, salary, dependents);

    send_message(message, msg_size);
}

void retirement(){
    char message[STR_LEN];
    int msg_size = 0;
    int age = 0;
    int years_worked = 0;

    printf("Entre com a idade do Funcionario.: ");
    scanf("%d", &age);

    printf("Entre com o Tempo trabalahdo do Funcionario.: ");
    scanf("%d", &years_worked);

    msg_size = sprintf(message, "G;%d;%d", age, years_worked);

    send_message(message, msg_size);
}

void special_credit(){
    char message[STR_LEN];
    int msg_size = 0;
    float average_balance;

    printf("Entre com saldo medio do ano.: ");
    scanf("%f", &average_balance);

    msg_size = sprintf(message, "H;%.2f", average_balance);

    send_message(message, msg_size);
}

void card_name(){
    char message[STR_LEN];
    int msg_size = 0;
    int card_number = 0;
    int card_suit = 0;

    printf("Entre com o numero da carta (De 1 a 13).: ");
    scanf("%d", &card_number);

    printf("Entre com o Naipe da carta (1 = ouros, 2 = paus, 3 = copas e 4 = espadas).: ");
    scanf("%d", &card_suit);

    msg_size = sprintf(message, "I;%d;%d", card_number, card_suit);

    send_message(message, msg_size);
}

int main(int argc, char const* argv[]){
    int pc = 0;
    printf("Exercicio de Sistemas Distribuidos\nCliente e Server escritos na mesma linguagem\n\n");
    printf("Escolha um exercicio:\n");
    printf("1. Reajuste salarial.\n");
    printf("2. Maioridade.\n");
    printf("3. Media para aprovacao.\n");
    printf("4. Peso ideal.\n");
    printf("5. Classificacao do Nadador.\n");
    printf("6. Salario liquido.\n");
    printf("7. Aposentadoria.\n");
    printf("8. Credito especial.\n");
    printf("9. Nome das cartas.\n\n");
    printf("Digite o numero de um exercicio para executar.: ");
    scanf("%d", &pc);
    getchar();

    switch(pc){
        case 1:
            salary_readjustment();
            break;
        case 2:
            majority();
            break;
        case 3:
            college_average();
            break;
        case 4:
            ideal_weight();
            break;
        case 5:
            swimmer_classification();
            break;
        case 6:
            net_salary();
            break;
        case 7:
            retirement();
            break;
        case 8:
            special_credit();
            break;
        case 9:
            card_name();
            break;
        default:
            printf("Nenhum exercicio valido escolhido");
    }
    return 0;
}