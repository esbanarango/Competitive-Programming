/*
  2149 - 01000001
  TJU Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com

*/

#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char *argv[]){
    int cases;
    int caso=1;
    scanf("%d",&cases);
    getchar();
    
    while(cases--){
           int numero1[100];
           int numero2[100];
           char aux;
           int num;

           scanf("%c",&aux);

           int x=0;
           int y=0;        
           for(;aux!=' ';scanf("%c",&aux)){
                       if(aux!=' '){
                                 num=atoi(&aux);
                                 numero1[x]=num;
                                 x++;
                        }                          
           }
           aux=getchar();
           for(;aux!='\n';scanf("%c",&aux)){
                        num=atoi(&aux);
                        numero2[y]=num;
                        y++;           
           }
           if(x-y>=0){                        
                        int carry=0;
                        int k;
                        k=y;
                        k--;
      
                        for (int j = x-1;j > -1;j--){
                            
                            if(k>=0){
                                         num= carry + numero1[j] + numero2[k];
                                         if(num>1){      
                                              numero1[j]=num-2;
                                              carry=1;
                                         }else{
                                               numero1[j]=num;
                                               carry=0; 
                                         }
                                         k--;
                            }else{
                                     num= carry + numero1[j] + 0;
                                     if(num>1){      
                                              numero1[j]=num-2;
                                              carry=1;
                                         }else{
                                               numero1[j]=num;
                                               carry=0; 
                                         }
                                  
                            }
                        }
                        printf("%d ", caso);
                        caso++;
                        int num0=0;
                        if (carry == 1){
                           printf("%d", 1);
                        }else{
                        for (int i = 0;i< x;i++){ 
                               if(numero1[i]==0){    
                                        num0++;                   
                               }else{
                                     i=x*x;
                               }
                               
                        }
                        }
                        if(num0==x){
                                printf("0");               
                        }
                        for (int i = 0+num0;i< x;i++){
                               printf("%d", numero1[i]);
                        }
                        printf("\n");
                  }else{
                        int carry=0;
                        int k;
                        k=x;
                        k--; 
      
                        for (int j = y-1;j > -1;j--){
                            if(k>=0){
                                         num= carry + numero2[j] + numero1[k];
                                         
                                         if(num>1){      
                                              numero2[j]=num-2;
                                              carry=1;
                                         }else{
                                               numero2[j]=num;
                                               carry=0; 
                                         }
                                         k--;
                            }else{
                                     num= carry + numero2[j] + 0;
                                     if(num>1){      
                                              numero2[j]=num-2;
                                              carry=1;
                                         }else{
                                               numero2[j]=num;
                                               carry=0; 
                                         }
                                  
                            }
                        }
                        printf("%d ", caso);
                        caso++;
                        int num0=0;
                        if (carry == 1){
                           printf("%d", 1);
                        }else{
                        for (int i = 0;i< y;i++){ 
                               if(numero2[i]==0){    
                                        num0++;                   
                               }else{
                                     i=y*y;
                               }
                               
                        }
                        }
                        if(num0==y){
                                printf("0");               
                        }
                        for (int i = 0+num0;i< y;i++){
                               printf("%d", numero2[i]);
                        }
                        printf("\n");
                  }                          

    }
    return 0;
}
