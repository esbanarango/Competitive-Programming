/*
  2149 - 01000001
  TJU Online Judge
  Esteban Arango Medina
  marranoparael31@gmail.com

*/
#include<vector>

using namespace std;

int main(int argc, char *argv[]){
    int cases;
    int caso=1;
    
    scanf("%d",&cases);
    getchar();
    
    while(cases--){
           vector<int> numero1;
           vector<int> numero2;
           char aux;
           int num;

           scanf("%c",&aux);

           int i=0;        
           for(;aux!=' ';scanf("%c",&aux)){
                       if(aux!=' '){
                                 num=atoi(&aux);
                                 numero1.push_back(num);
                        }                          
           }
           aux=getchar();
           for(;aux!='\n';scanf("%c",&aux)){
                        num=atoi(&aux);
                        numero2.push_back(num);           
           }
           int tam1=numero1.size();
           int tam2=numero2.size();

           if(tam1-tam2>=0){                        
                        int carry=0;
                        int k;
                        k=numero2.size();
      
                        for (int j = tam1-1;j > -1;j--){
                            
                            if(k--){
                                         num= carry + numero1[j] + numero2[k]; 
                                         if(num==2 || num==3){      
                                              numero1[j]=num-2;
                                              carry=1;
                                         }  
                                         if(num==1 || num==0){
                                               numero1[j]=num;
                                               carry=0; 
                                         }
                            }else{
                                     num= carry + numero1[j] + 0;
                                     if(num==2){      
                                              numero1[j]=0;
                                              carry=1;
                                     }
                                     if(num==1 || num==0){
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
                        for (int i = 0;i< tam1;i++){ 
                               if(numero1[i]==0){    
                                        num0++;                   
                               }else{
                                     i=tam1*tam1;
                               }
                               
                        }
                        }
                        if(num0==tam1){
                                printf("0");               
                        }
                        for (int i = 0+num0;i< tam1;i++){
                               printf("%d", numero1[i]);
                        }
                        printf("\n");
                  }else{
                        int carry=0;
                        int k;
                        k=numero1.size();
                         
      
                        for (int j = tam2-1;j > -1;j--){
                            if(k--){
                                         num= carry + numero2[j] + numero1[k];
                                         
                                         if(num==2 || num==3){      
                                              numero2[j]=num-2;
                                              carry=1;
                                         }    
                                         if(num==1 || num==0){
                                               numero2[j]=num;
                                               carry=0; 
                                         }
                            }else{
                                     num= carry + numero2[j] + 0;
                                     if(num==2){      
                                              numero2[j]=0;
                                              carry=1;
                                     }
                                     if(num==1 || num==0){
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
                        for (int i = 0;i< tam2;i++){ 
                               if(numero2[i]==0){    
                                        num0++;                   
                               }else{
                                     i=tam1*tam1;
                               }
                               
                        }
                        }
                        if(num0==tam2){
                                printf("0");               
                        }
                        for (int i = 0+num0;i< tam2;i++){
                               printf("%d", numero2[i]);
                        }
                        printf("\n");
                  }                              
    }
    return 0;
}
