#include<stdio.h>
#include <unistd.h>
#include<conio.h>
#include<windows.h>
#include<regex>
char ch[] = {"........."};

bool check(int a,int b){
    return (a>=0&&a<3&&b>=0&&b<3);
}

bool gameOverCheck(){
    return std::regex_match (ch, std::regex("(X|O)(..(\\1|.\\1.)..\\1|.\\1.\\1..$|\\1\\1(...)*$)") );
}

int main(){
    int a = 0,b = 0,x = 0;
    bool player = 0;
    int tot = 0;
    while(tot<9){
        system("cls");
        char m = 0;
        if(kbhit()){
            x = 1;
            m = getch();
            switch(m){
            case 75:
                if(check(a,b-1)){
                    b -= 1;
                }
                break;
            case 72:
                if(check(a-1,b)){
                    a -= 1;
                }
                break;
            case 77:
                if(check(a,b+1)){
                    b += 1;
                }
                break;
            case 80:
                if(check(a+1,b)){
                    a += 1;
                }
                break;
            case 13:
                if(ch[a*3 + b] == '.'){
                    if(player){
                        ch[a*3 + b] = 'X';
                    }else{
                        ch[a*3 + b] = 'O';
                    }
                    tot++;
                    if(gameOverCheck()){
                        printf("Player %c Win",player?'X':'O');
                        exit(0);
                    }
                     player = !player;
                }
                break;
            }
        }
        int c = 0;
        for(int i = 0;i<3;++i){
            for(int j = 0;j<3;++j){
                if(i == a && j == b && x){
                    printf("_");
                }else{
                    printf("%c",ch[c]);
                }
                ++c;
            }
            puts("");
        }
        x = (x+1)%2;
        usleep(200000);
    }
}
