import socket

HOST = '127.0.0.1'
PORT = 8080

def salary_readjustment():
    print("Entre com o Nome do Funcionario.:")
    name = input()

    print("Entre com o Cargo do Funcionario.: ")
    office = input()

    print("Entre com o Salario do Funcionario(Formato 00.00).: ")
    salary = input()

    msg = str('A;'+name+';'+office+';'+salary)

    sendMessageWaitResponse(msg)


def majority():
    print("Entre com o Nome da pessoa.: ")
    name = input()

    print("Entre com o Sexo da pessoa(M ou F).: ")
    sex = input()

    print("Entre com a idade da pessoa.: ")
    age = input()

    msg = str('B;'+name+';'+sex+';'+age)

    sendMessageWaitResponse(msg)

def college_average():
    print("Entre com a primeira nota.: ")
    n1 = input()

    print("Entre com a segunda nota.: ")
    n2 = input()

    print("Entre com a terceira nota.: ")
    n3 = input()

    msg = str('C;'+n1+';'+n2+';'+n3)

    sendMessageWaitResponse(msg)

def ideal_weight():
    print("Entre com o sexo da pessoa.: ")
    sex = input()

    print("Entre com o peso da pessoa.: ")
    height = input()

    msg = str('D;'+sex+';'+height)

    sendMessageWaitResponse(msg)

def swimmer_classification():
    print("Entre com a idade do nadador.: ")
    age = input()

    msg = str('E;'+age)

    sendMessageWaitResponse(msg)

def net_salary():
    print("Entre com o Nome do Funcionario.: ")
    name = input()

    print("Entre com o Nivel do Funcionario.: ")
    level = input()

    print("Entre com o Salario Bruto do Funcionario(Formato 00.00).: ")
    salary = input()

    print("Entre com a quantidade de dependentes do Funcionario.: ")
    dependents = input()

    msg = str('F;'+name+';'+level+';'+salary+';'+dependents)

    sendMessageWaitResponse(msg)

def retirement():
    print("Entre com a idade do Funcionario.: ")
    age = input()

    print("Entre com o Tempo trabalahdo do Funcionario.: ")
    years_worked = input()

    msg = str('G;'+age+';'+years_worked)

    sendMessageWaitResponse(msg)

def special_credit():
    print("Entre com saldo medio do ano.: ")
    average_balance = input()

    msg = str('H;'+average_balance)

    sendMessageWaitResponse(msg)

def card_name():
    print("Entre com o numero da carta (De 1 a 13).: ")
    card_number = input()

    print("Entre com o Naipe da carta (1 = ouros, 2 = paus, 3 = copas e 4 = espadas).: ")
    card_suit = input()

    msg = str('I;'+card_number+';'+card_suit)

    sendMessageWaitResponse(msg)


def card_name():
    sendMessageWaitResponse()

def sendMessageWaitResponse(msg):
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((HOST,PORT))

    s.sendall(str.encode(msg))

    data = s.recv(1024)

    data = data.decode()

    print('\nResposta do servidor.:\n', data)


print("Exercicio de Sistemas Distribuidos\nCliente e Server escritos em linguagens diferentes.\n");
print("Escolha um exercicio:");
print("1. Reajuste salarial.");
print("2. Maioridade.");
print("3. Media para aprovacao.");
print("4. Peso ideal.");
print("5. Classificacao do Nadador.");
print("6. Salario liquido.");
print("7. Aposentadoria.");
print("8. Credito especial.");
print("9. Nome das cartas.\n");
print("Digite o numero de um exercicio para executar.: ");

exercicio = input()

if(exercicio == '1'):
    salary_readjustment()
elif(exercicio == '2'):
    majority()
elif(exercicio == '3'):
    college_average()
elif(exercicio == '4'):
    ideal_weight()
elif(exercicio == '5'):
    swimmer_classification()
elif(exercicio == '6'):
    net_salary()
elif(exercicio == '7'):
    retirement()
elif(exercicio == '8'):
    special_credit()
elif(exercicio == '9'):
    card_name()
else:
    print('Nenhum exercicio valido escolhido')
