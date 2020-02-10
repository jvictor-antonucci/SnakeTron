#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<string.h>

int x = 0, y = 0, d = 2, c2x[500] = {48}, c2y[500] = {20}, c1x[500] = {2}, c1y[500] = {20}, t = 3, mx, my, score = 0, vel, varmazenar[5]={0,0,0,0,0}, i = 0, a = 0, t2 = 3, d2 = 0;
char nome[16], vnome[5][16];

void mgotoxy(int x,int y){
    COORD p = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);
}

void armazenaPlayer(){
    if(a > 5){
        a = a%5;
    }
    strcpy(vnome[a], nome);
    return 0;
}

void derrota(){
    int l, j, aux;
    char aux1[16];
    system("cls");
    getch();
    mgotoxy(37, 13);
    printf("Voc%c Perdeu!\n", 136);
    mgotoxy(37, 15);
    printf("Sua pontua%c%co: %d", 135, 198, score);
    getch();
    if(varmazenar[i] != 0){
        i++;
    }
    varmazenar[i] = score;
    armazenaPlayer();
    for( l = 0; l < 5; l++ ){
        for(j = l+1; j < 5; j++){
            if(varmazenar[l] < varmazenar[j]){
                aux = varmazenar[l];
                varmazenar[l] = varmazenar[j];
                varmazenar[j] = aux;
                strcpy(aux1, vnome[l]);
                strcpy(vnome[l], vnome[j]);
                strcpy(vnome[j], aux1);
            }
        }
    }
    system("cls");
    fflush(stdin);
    score = 0;
    c1x[0] = 14;
    c1y[0] = 14;
    t = 3;
    d = 2;
    a++;
    menu();
}

void Sair(){
    mgotoxy(37, 13);
    printf("Obrigado por jogar SnakeTron!");
    mgotoxy(37, 15);
    printf("Finalizando jogo...");
    Sleep(450);
    system("cls");
    exit(0);
}


int perfilCobra(){
    mgotoxy(35, 15);
    printf("Escolha um nome:");
    fflush(stdin);
    gets(nome);
    system("cls");
    return 0;
}

int veloc(){
    char escolha;
    mgotoxy(35, 15);
    printf("Escolha a velocidade: ");
    mgotoxy(35, 16);
    printf("\t(1) Velocidade >");
    mgotoxy(35, 17);
    printf("\t(2) Velocidade >>");
    mgotoxy(35, 18);
    printf("\t(3) Velocidade >>>");
    mgotoxy(35, 19);
    printf("\t(4) Velocidade >>>>");
    mgotoxy(35, 20);
    printf("\t(5) Velocidade >>>>>");
    mgotoxy(35, 21);
    printf("\t(6) Velocidade >>>>>>");
    mgotoxy(56, 15);
    do{
        escolha = getch();
        if(escolha == '1'){
            vel = 300;
        }else if(escolha == '2'){
            vel = 200;
        }else if(escolha == '3'){
            vel = 150;
        }else if(escolha == '4'){
            vel = 100;
        }else if(escolha == '5'){
            vel = 50;
        }else if(escolha == '6'){
            vel = 20;
        }
    }while(escolha != '1' && escolha != '2' && escolha != '3' && escolha != '4' && escolha != '5' && escolha != '6');
    system("cls");
    return vel;
}

void derrotaP1(){
    system("cls");
    mgotoxy(37, 20);
    printf("O player 1 (%c) perdeu!", 2);
    mgotoxy(37, 21);
    printf("O vencedor %c o player 2. Parab%cns!", 130, 130);
    getch();
    system("cls");
    c2x[0] = 48;
    c2y[0] = 20;
    c1x[0] = 2;
    c1y[0] = 20;
    t = 3;
    t2 = 3;
    d = 2;
    d2 = 0;
    menu();
}

void derrotaP2(){
    system("cls");
    mgotoxy(37, 20);
    printf("O player 2 (%c) perdeu!", 1);
    mgotoxy(37, 21);
    printf("O vencedor %c o player 1. Parab%cns!", 130, 130);
    getch();
    system("cls");
    c2x[0] = 48;
    c2y[0] = 20;
    c1x[0] = 2;
    c1y[0] = 20;
    t2 = 3;
    d = 2;
    d2 = 0;
    menu();
}

void snake2(){
    char tecla = ' ';
     for(x = t2; x > 0; x--){
                c2x[x] = c2x[x-1];
                c2y[x] = c2y[x-1];
            }
            if(d2 == 0){c2x[0]--;
            }
            if(d2 == 1){c2y[0]--;
            }
            if(d2 == 2){c2x[0]++;
            }
            if(d2 == 3){c2y[0]++;
            }
            mgotoxy(c2x[t2],c2y[t2]);
            printf(" ");
            if(mx == c2x[0] && my == c2y[0]){
                t2++;
                mx = (rand()%48)+1;
                my = (rand()%38)+1;
                mgotoxy(mx, my);
                printf("%c", 208);
            }
            for(x = 1; x < t2; x++){
                if(mx == c2x[x] && my == c2y[x]){
                    mgotoxy(mx, my);
                    printf("%c", 1);
                    mx = (rand()%48)+1;
                    my = (rand()%38)+1;
                    mgotoxy(mx, my);
                    printf("%c", 208);
                }
            }
            mgotoxy(c2x[0], c2y[0]);
            printf("%c", 1);
        if(tecla == 75){
            d2 = 0;
        }
        if(tecla == 72){
            d2 = 1;
        }
        if(tecla == 77){
            d2 = 2;
        }
        if(tecla == 80){
            d2 = 3;
        }
        for(x = 1; x < t2; x++){
                if(c2x[0] == c2x[x] && c2y[0] == c2y[x]){
                    tecla = 'L';
                    getch();
                    derrotaP2();
                }
                if(c1x[0] == c2x[x] && c1y[0] == c2y[x]){
                    tecla = 'L';
                    getch();
                    derrotaP1();
                }
            }
}

void modoTron(){
    char tecla = ' ';
    system("cls");
    vel = veloc();
    system("color 0A");
    mgotoxy(0,0);
    printf("%c", 201);
    for(x = 1; x < 40; x++){
        mgotoxy(0,x);
        printf("%c", 186);
    }
    mgotoxy(0,40);
    printf("%c", 200);
    for(x = 1; x < 50; x++){
        mgotoxy(x,40);
        printf("%c", 205);
    }
    mgotoxy(50,40);
    printf("%c", 188);
    for(x = 1; x < 40; x++){
        mgotoxy(50,x);
        printf("%c", 186);
    }
    mgotoxy(50,0);
    printf("%c", 187);
    for(x = 1; x < 50; x++){
        mgotoxy(x,0);
        printf("%c", 205);
    }
    srand(time(NULL));
    mx = (rand()%48)+1;
    my = (rand()%23)+1;
    mgotoxy(mx, my);
    printf("%c", 208);
    while(tecla != 'L'){
        while(tecla != 'L' &&! (tecla = kbhit())){
            snake2();
            for(x = t; x > 0; x--){
                c1x[x] = c1x[x-1];
                c1y[x] = c1y[x-1];
            }

            if(d == 0){c1x[0]--;
            }
            if(d == 1){c1y[0]--;
            }
            if(d == 2){c1x[0]++;
            }
            if(d == 3){c1y[0]++;
            }
            mgotoxy(c1x[t],c1y[t]);
            printf(" ");
            if(mx == c1x[0] && my == c1y[0]){
                score+= 10;
                t++;
                mx = (rand()%48)+1;
                my = (rand()%23)+1;
                mgotoxy(mx, my);
                printf("%c", 208);
            }
            for(x = 1; x < t; x++){
                if(mx == c1x[x] && my == c1y[x]){
                    mgotoxy(mx, my);
                    printf("%c", 2);
                    mx = (rand()%48)+1;
                    my = (rand()%23)+1;
                    mgotoxy(mx, my);
                    printf("%c", 208);
                }
            }
            mgotoxy(c1x[0],c1y[0]);
            printf("%c", 2);
            Sleep(vel);
            if(c1x[0] == 0 || c1x[0] == 50 || c1y[0] == 0 || c1y[0] == 40){
                tecla = 'L';
                getch();
                derrotaP1();
            }
            if(c2x[0] == 0 || c2x[0] == 50 || c2y[0] == 0 || c2y[0] == 40){
                tecla = 'L';
                getch();
                derrotaP2();
            }
            for(x = 1; x < t; x++){
                if(c1x[0] == c1x[x] && c1y[0] == c1y[x]){
                    tecla = 'L';
                    getch();
                    derrotaP1();
                }
                if(c2x[0] == c1x[x] && c2y[0] == c1y[x]){
                    tecla = 'L';
                    getch();
                    derrotaP2();
                }
            }
        }
        if(tecla != ' '){
            tecla = getch();
        }
        if(tecla == 'a'){
            d = 0;
        }
        if(tecla == 'w'){
            d = 1;
        }
        if(tecla == 'd'){
            d = 2;
        }
        if(tecla == 's'){
            d = 3;
        }
        if(tecla == 75){
            d2 = 0;
        }
        if(tecla == 72){
            d2 = 1;
        }
        if(tecla == 77){
            d2 = 2;
        }
        if(tecla == 80){
            d2 = 3;
        }
    }
    getch();
}

void inicioJogo(){
    char tecla = 'd';
    system("cls");
    perfilCobra();
    vel = veloc();
    system("color 0A");
    mgotoxy(0,0);
    printf("%c", 201);
    for(x = 1; x < 25; x++){
        mgotoxy(0,x);
        printf("%c", 186);
    }
    mgotoxy(0,25);
    printf("%c", 200);
    for(x = 1; x < 50; x++){
        mgotoxy(x,25);
        printf("%c", 205);
    }
    mgotoxy(50,25);
    printf("%c", 188);
    for(x = 1; x < 25; x++){
        mgotoxy(50,x);
        printf("%c", 186);
    }
    mgotoxy(50,0);
    printf("%c", 187);
    for(x = 1; x < 50; x++){
        mgotoxy(x,0);
        printf("%c", 205);
    }
    mgotoxy(57, 10);
    printf("Nome: %s", nome);
    srand(time(NULL));
    mx = (rand()%48)+1;
    my = (rand()%23)+1;
    mgotoxy(mx, my);
    printf("%c", 208);
    while(tecla != 'L'){
        while(tecla != 'L' &&! (tecla = kbhit())){
            for(x = t; x > 0; x--){
                c1x[x] = c1x[x-1];
                c1y[x] = c1y[x-1];
            }
            if(d == 0){c1x[0]--;
            }
            if(d == 1){c1y[0]--;
            }
            if(d == 2){c1x[0]++;
            }
            if(d == 3){c1y[0]++;
            }
            mgotoxy(c1x[t],c1y[t]);
            printf(" ");
            if(mx == c1x[0] && my == c1y[0]){
                score+= 10;
                t++;
                mx = (rand()%48)+1;
                my = (rand()%23)+1;
                mgotoxy(mx, my);
                printf("%c", 208);
            }
            for(x = 1; x < t; x++){
                if(mx == c1x[x] && my == c1y[x]){
                    mgotoxy(mx, my);
                    printf("%c", 2);
                    mx = (rand()%48)+1;
                    my = (rand()%23)+1;
                    mgotoxy(mx, my);
                    printf("%c", 208);
                }
            }
            mgotoxy(57, 13);
            printf("Pontua%c%co: %d", 135, 198,score);
            mgotoxy(c1x[0],c1y[0]);
            printf("%c", 2);
            Sleep(vel);
            if(c1x[0] == 0 || c1x[0] == 50 || c1y[0] == 0 || c1y[0] == 25){
                tecla = 'L';
                getch();
                derrota();
            }
            for(x = 1; x < t; x++){
                if(c1x[0]==c1x[x] && c1y[0]==c1y[x]){
                    tecla = 'L';
                    getch();
                    derrota();
                }
            }
        }
        if(tecla != ' '){tecla = getch();
        }
        if(tecla == 'a' || tecla == '1' || tecla == 75){d = 0;
        }
        if(tecla == 'w' || tecla == '2' || tecla == 72){d = 1;
        }
        if(tecla == 'd' || tecla == '3' || tecla == 77){d = 2;
        }
        if(tecla == 's' || tecla == '4' || tecla == 80){d = 3;
        }
    }
    getch();
}

void apagarcaracter(int x, int y){
    mgotoxy(x,y);
    printf(" ");
}
void creditos(){
    int i=0;

struct creditos{
    char nome[30];
    char nivel[20];
    char escola[30];
};

    typedef struct creditos creditos;
    creditos *p;
    creditos k;
    p=&k;

    creditos vetor[4];

    mgotoxy(26,3);
        printf("INTEGRANTES");
    mgotoxy(24,16);
        printf("AGRADECIMENTOS");

    mgotoxy(5,5);
        strcpy(vetor[i].nome,"Guilherme Pinto Fernandes");
        printf("%s", vetor[i].nome);
        i++;
    mgotoxy(5,9);
        strcpy(vetor[i].nome,"Joao Victor Antonucci Sardinha");
        printf("%s", vetor[i].nome);
        i++;
    mgotoxy(5,13);
        strcpy(vetor[i].nome,"Victor Melo de Lucas Brandao");
        printf("%s", vetor[i].nome);
        i++;
    mgotoxy(5,18);
        strcpy(vetor[i].nome,"Paulo Cesar Ferreira Melo");
        printf("%s", vetor[i].nome);
        i=0;
    mgotoxy(5,6);
        strcpy(vetor[i].escola,"EMC");
        printf("%s", vetor[i].escola);
    mgotoxy(5,10);
        strcpy(vetor[i].escola,"EMC");
        printf("%s", vetor[i].escola);
    mgotoxy(5,14);
        strcpy(vetor[i].escola,"EMC");
        printf("%s", vetor[i].escola);
        i++;
    mgotoxy(5,19);
        strcpy(vetor[i].escola,"INF");
        printf("%s", vetor[i].escola);
        i=0;
    mgotoxy(10,6);
        strcpy(vetor[i].nivel,"Discente em Engenharia de Computacao");
        printf("%s",vetor[i].nivel);
    mgotoxy(10,10);
        strcpy(vetor[i].nivel,"Discente em Engenharia de Computacao");
        printf("%s",vetor[i].nivel);
    mgotoxy(10,14);
        strcpy(vetor[i].nivel,"Discente em Engenharia de Computacao");
        printf("%s",vetor[i].nivel);
        i++;
    mgotoxy(10,19);
        strcpy(vetor[i].nivel,"Mestre em Ciencia da Computacao");
        printf("%s",vetor[i].nivel);
    mgotoxy(20,22);
        printf("\"Stay hungry, stay foolish\"");
    mgotoxy(22,23);
        printf("-Steve Jobs");
    getch();
    system("cls");
    main();
}

void regras(){
    int matriz[5][2]={{1,300},{2,200},{3,150},{4,100},{5,50}};

    mgotoxy(20,1);
        printf("INICIAR\n\n");
        printf("-> Ao escolher inicar, insira o seu nome.\n");
        printf("-> Escolha a velocidade que deseja jogar.");
    mgotoxy(10,6);
        printf("Escolha");
    mgotoxy(19,6);
        printf("Velocidade(ms)");
    mgotoxy(10,8);
        printf("%i",matriz[0][0]);
    mgotoxy(10,9);
        printf("%i",matriz[1][0]);
    mgotoxy(10,10);
        printf("%i",matriz[2][0]);
    mgotoxy(10,11);
        printf("%i",matriz[3][0]);
    mgotoxy(10,12);
        printf("%i",matriz[4][0]);
    mgotoxy(19,8);
        printf("%i",matriz[0][1]);
    mgotoxy(19,9);
        printf("%i",matriz[1][1]);
    mgotoxy(19,10);
        printf("%i",matriz[2][1]);
    mgotoxy(19,11);
        printf("%i",matriz[3][1]);
    mgotoxy(19,12);
        printf("%i\n\n",matriz[4][1]);
        printf("-> Comece a jogar e tente pegar o m%cximo de frutas poss%cveis.",160,161);
    mgotoxy(19,16);
        printf("RECORDES\n\n");
        printf("-> Armazenamento das maiores pontua%c%ces.",135,228);
    mgotoxy(19,20);
        printf("CREDITOS\n\n");
        printf("-> Perfil dos criadores e agradecimentos.");
    mgotoxy(19,24);
        printf("MODO TRON\n\n");
        printf("-> Ser%co dois jogadores, um se move nas setas e o outros nas teclas(a,s,d,w).\n",198);
        printf("-> Se um jogador encostar no outro, este ir%c perder o jogo.\n", 160);
        printf("-> Consequentemente, o que pegar mais frutas, tera vantagem.\n");
    mgotoxy(21,30);
        printf("SAIR\n\n");
        printf("-> Usado para finalizar o jogo.");
    getch();
    system("cls");
    main();
}

void recordes(){
            int k=0;


            mgotoxy(30,4);
            printf("RECORDES");
            mgotoxy(23,7);
            printf("1.Nome:%s........................Pontos:%i", vnome[k], varmazenar[k]);
            k++;
            mgotoxy(23,9);
            printf("2.Nome:%s........................Pontos:%i", vnome[k], varmazenar[k]);
            k++;
            mgotoxy(23,11);
            printf("3.Nome:%s........................Pontos:%i", vnome[k], varmazenar[k]);
            k++;
            mgotoxy(23,13);
            printf("4.Nome:%s........................Pontos:%i", vnome[k], varmazenar[k]);
            k++;
            mgotoxy(23,15);
            printf("5.Nome:%s........................Pontos:%i", vnome[k], varmazenar[k]);
    getch();
    system("cls");
    menu();
}

int menu(){
    int j = 15;
    char tecla = ' ';
    system("color 0A");
    do{
         mgotoxy(0,6);
        printf("%c%c%c%c%c%c%c %c%c   %c%c    %c%c    %c%c   %c%c %c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c %c%c%c%c%c%c%c    %c%c%c%c    %c%c   %c%c \n", 254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254);
        printf("%c%c%c%c%c%c%c %c%c%c  %c%c   %c  %c   %c%c  %c%c  %c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c %c%c%c%c%c%c%c   %c%c%c%c%c%c   %c%c%c  %c%c \n", 254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254);
        printf("%c%c      %c%c%c%c%c%c%c  %c%c  %c%c  %c%c %c%c   %c%c          %c%c    %c%c   %c%c  %c%c%c  %c%c%c  %c%c%c%c%c%c%c \n", 254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254);
        printf("%c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c  %c%c%c %c%c%c%c    %c%c%c%c%c%c%c%c    %c%c    %c%c%c%c%c%c%c %c%c%c    %c%c%c %c%c%c%c%c%c%c \n", 254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254);
        printf("%c%c%c%c%c%c%c %c%c  %c%c%c %c%c%c%c%c%c%c%c %c%c%c%c    %c%c%c%c%c%c%c%c    %c%c    %c%c%c%c%c   %c%c%c    %c%c%c %c%c  %c%c%c \n", 254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254);
        printf("     %c%c %c%c  %c%c%c %c%c%c  %c%c%c %c%c %c%c   %c%c          %c%c    %c%c %c%c    %c%c%c  %c%c%c  %c%c  %c%c%c \n", 254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254);
        printf("%c%c%c%c%c%c%c %c%c   %c%c %c%c    %c%c %c%c  %c%c  %c%c%c%c%c%c%c%c    %c%c    %c%c  %c%c    %c%c%c%c%c%c   %c%c   %c%c \n", 254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254);
        printf("%c%c%c%c%c%c%c %c%c   %c%c %c%c    %c%c %c%c   %c%c %c%c%c%c%c%c%c%c    %c%c    %c%c   %c%c    %c%c%c%c    %c%c   %c%c \n", 254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254);

        mgotoxy(37,15);
        printf("INICIAR");
        mgotoxy(37,17);
        printf("MODO TRON");
        mgotoxy(37,19);
        printf("REGRAS");
        mgotoxy(37,21);
        printf("RECORDES");
        mgotoxy(37,23);
        printf("CR%cDITOS", 144);
        mgotoxy(37, 25);
        printf("SAIR");
        mgotoxy(35,j);
        printf("%c", 16);
        tecla = getch();

        if(tecla == 80){
            apagarcaracter(35,j);
            switch(j){
                case 15:
                    j = 17;
                    break;
                case 17:
                    j = 19;
                    break;
                case 19:
                    j = 21;
                    break;
                case 21:
                    j = 23;
                    break;
                case 23:
                    j = 25;
                    break;
                default:
                    j = 15;
                    break;
            }
        }else if(tecla == 72){
            apagarcaracter(35,j);
            switch(j){
                case 25:
                    j = 23;
                    break;
                case 23:
                    j = 21;
                    break;
                case 21:
                    j = 19;
                    break;
                case 19:
                    j = 17;
                    break;
                case 17:
                    j = 15;
                    break;
                default:
                    j = 25;
                    break;
            }
        }
    }while(tecla != '\r');

    switch(j){
        case 15:
            system("cls");
            score = 0;
            c1x[0] = 14;
            c1y[0] = 14;
            t = 3;
            d = 2;
            inicioJogo();
            break;
        case 17:
            c2x[0] = 48;
            c2y[0] = 20;
            c1x[0] = 2;
            c1y[0] = 20;
            t = 3;
            t2 = 3;
            d = 2;
            d2 = 0;
            system("cls");
            modoTron();
            break;
        case 19:
            system("cls");
            regras();
            break;
        case 21:
            system("cls");
            recordes();
            break;
        case 23:
            system("cls");
            creditos();
            break;
        default:
            system("cls");
            Sair();
    }
    system("cls");
}

main(){
    menu();
}

