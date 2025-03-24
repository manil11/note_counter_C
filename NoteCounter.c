#include<stdio.h>
#include<string.h>

void calculateTotalAmount();
void clearALL();
void read();

int check(int a);


int main(){

    int x;
    printf("Welcome to the Money Counter Application! \nPlease choose an option from the menu below.\n");

    printf("1.Calculate Money\n2.View History\n3.Clear History\n4.Exit\n");
    scanf("%d",&x);
    switch (x)
    {
    case 1: calculateTotalAmount();break;
    case 2: read();break;
    case 3: clearALL();break;
    case 4 :printf("Exit\n");break;
    
    default:printf("Invalid Input. Please try again.\n");
        break;
    }
    
  printf("\nFile closed");
}


void clearALL(){
    FILE *file;
    char a;
    printf("Are you Sure You Want to delete all History (y/n):");
    scanf(" %c",&a);
    if(a == 'y'|| a=='Y'){
         file = fopen("History.txt","w");
         if (file == NULL) {
        printf("Error Opening the file\n");
        return;
        }
    fclose(file);

    printf("Your history has been successfully cleared.\n");
    }
    else{
    printf("Delete Cancel");
}

}


void calculateTotalAmount()
{
    FILE *file;
    file = fopen("History.txt","a");
     if(file == NULL){
        file = fopen("History.txt","w");
        if(file == NULL){
            printf("Error: Unable to open or create file.\n");
            return;
        }
        printf("Unable to find existing file , so Creating new file ");
    }
    
    int arr[] = {500,200,100,50,20,10,5,2,1};
    int val[9]={} ;
    int total =0;
    printf("Enter the No of notes u have of each demonation :\n");
    for(int i = 0 ;i<9;i++){
        printf("%d :",arr[i]);

        scanf("%d", &val[i]);
        val[i] = check(val[i]);


        fprintf(file,"%d : %d \n",arr[i],val[i]);
    }
    for (int i = 0; i < 9; i++) {
        total+= arr[i] * val[i];     
    }

    printf("The Total amount u got is %d",total);
    fprintf(file,"----------------\nTotal: %d\n\n",total);
    fclose(file);   
}



void read(){
    FILE *file;
    file = fopen("History.txt","r");
    if (file == NULL) {
        printf("Error opening file");  
        return;
        
    }
    char buffer[256];
    int isEmpty = 1;
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer); 
        isEmpty =0;
        
    }
    if(isEmpty){
        printf("File is Empty");
    }

    fclose(file);
}

int check(int a){


    if(a!= 1 && a <0){
        
        printf("Invalid Entry\nEnter Again :");
        int c ;
        scanf("%d",&c);
        check(c);


    }
    else{

        return a;
    }
}