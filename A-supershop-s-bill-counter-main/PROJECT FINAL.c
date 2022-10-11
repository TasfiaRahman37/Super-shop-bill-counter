#include<stdio.h>
#include<string.h>

int menuP(int i){

    int o;

    if(i == 1) o=70;
    if(i == 2) o=40;
    if(i == 3) o=35;
    if(i == 4) o=60;
    if(i == 5) o=90;
    if(i == 6) o=120;
    if(i == 7) o=300;
    if(i == 8) o=400;
    if(i == 9) o=800;
    if(i == 10) o=600;
    if(i == 11) o=140;
    if(i == 12) o=200;
    if(i == 13) o=700;
    if(i == 14) o=200;
    if(i == 15) o=40;
    if(i == 16) o=80;
    if(i == 17) o=160;
    if(i == 18) o=100;
    if(i == 19) o=45;
    if(i == 20) o=35;
    if(i == 21) o=40;
    if(i == 22) o=50;
    if(i == 23) o=20;
    if(i == 24) o=135;
    if(i == 25) o=70;
    if(i == 26) o=75;
    if(i == 27) o=32;
    if(i == 28) o=55;
    if(i == 29) o=200;
    if(i == 30) o=60;


    return o;
}

int main(){

    int order[50], rem_order[50];
    int quantity[50], rem_quantity[50];
    int i,n,o;
    int mark, count=0;
    float bill[1000], total = 0.00;
    char item[20];
    char name[50];
    char tmp;
    char menu, memo;
    char fb;

    FILE *m=fopen("Menu.txt","r");

    while((menu=fgetc(m))!=EOF){
        printf("%c",menu);
    }

    fclose(m);

    printf("\nCustomer name: ");
    gets(name);

    FILE *f=fopen(name,"a");
    fprintf(f,"Customer name: %s\n", name);
    fclose(f);

    printf("Place your order- \n");

    for(int i=1 ;; i++){

        printf("Order #%d: ",i);
        scanf("%d", &order[i]);
        if(order[i] == 0) break;
        printf("Place Your quantity: ");
        scanf("%d", &quantity[i]);

        count++;


        o=menuP(order[i]);

        int p= o*quantity[i] ;
        bill[i] = p + (p*0.15);
        total = total + bill[i];

    }

    printf("\n");
    printf("Your orders-\n");

    f=fopen(name,"a");
    fprintf(f,"\nYour orders:\n\n");

    fclose(f);


    for(int i=1; i<=count; i++){

        if(order[i] == 1) strcpy(item,"Rice");
        if(order[i] == 2) strcpy(item,"Wheat");
        if(order[i] == 3) strcpy(item,"Flour");
        if(order[i] == 4) strcpy(item,"Bread");
        if(order[i] == 5) strcpy(item,"Breakfast Cereal");
        if(order[i] == 6) strcpy(item,"Chicken");
        if(order[i] == 7) strcpy(item,"Beef");
        if(order[i] == 8) strcpy(item,"Mutton");
        if(order[i] == 9) strcpy(item,"Ilish");
        if(order[i] == 10) strcpy(item,"Tuna Can");
        if(order[i] == 11) strcpy(item,"Soybean Oil");
        if(order[i] == 12) strcpy(item,"Mustard Oil");
        if(order[i] == 13) strcpy(item,"Olive Oil");
        if(order[i] == 14) strcpy(item,"Butter");
        if(order[i] == 15) strcpy(item,"Eggs");
        if(order[i] == 16) strcpy(item,"Milk");
        if(order[i] == 17) strcpy(item,"Cheese") ;
        if(order[i] == 18) strcpy(item,"Yogurt");
        if(order[i] == 19) strcpy(item,"Onions");
        if(order[i] == 20) strcpy(item,"Garlic");
        if(order[i] == 21) strcpy(item,"Ginger");
        if(order[i] == 22) strcpy(item,"Tomato");
        if(order[i] == 23) strcpy(item,"Potato");
        if(order[i] == 24) strcpy(item,"Red Capcicum");
        if(order[i] == 25) strcpy(item,"Green Capcicum");
        if(order[i] == 26) strcpy(item,"Sugar");
        if(order[i] == 27) strcpy(item,"Salt");
        if(order[i] == 28) strcpy(item,"Pepper");
        if(order[i] == 29) strcpy(item,"Honey");
        if(order[i] == 30) strcpy(item,"Vinegar");


        printf("%s ------ > %dx  ------ > %.2f Taka\n", item, quantity[i], bill[i]);

        FILE *f=fopen(name,"a");
        fprintf(f,"%s ------ > %dx  ------ > %.2f Taka\n", item, quantity[i], bill[i]);

        fclose(f);
    }

    while(-1){

        printf("\nDo you want to add or remove something?\n1. Add\n2. Remove\n3. No! Show my total bill\nButton no: ");

        int dc;
        scanf("%d", &dc);


        if(dc==1){

            count=0;
            for(int j=1;; j++){

                printf("Order #%d: ",j);
                scanf("%d", &order[j]);

                if(order[j] == 0) break;
                printf("Place Your quantity: ");
                scanf("%d", &quantity[j]);
                count++;


                o=menuP(order[j]);

                int p= o*quantity[j] ;
                bill[j] = p + (p*0.15);
                total = total + bill[j];
            }

            printf("\n");
            printf("Additions-\n");

            f=fopen(name,"a");
            fprintf(f,"\nAdditions-\n");

            fclose(f);

            for(int j=1; j<=count; j++){

                if(order[j] == 1) strcpy(item,"Rice");
                if(order[j] == 2) strcpy(item,"Wheat");
                if(order[j] == 3) strcpy(item,"Flour");
                if(order[j] == 4) strcpy(item,"Bread");
                if(order[j] == 5) strcpy(item,"Breakfast Cereal");
                if(order[j] == 6) strcpy(item,"Chicken");
                if(order[j] == 7) strcpy(item,"Beef");
                if(order[j] == 8) strcpy(item,"Mutton");
                if(order[j] == 9) strcpy(item,"Ilish");
                if(order[j] == 10) strcpy(item,"Tuna Can");
                if(order[j] == 11) strcpy(item,"Soybean Oil");
                if(order[j] == 12) strcpy(item,"Mustard Oil");
                if(order[j] == 13) strcpy(item,"Olive Oil");
                if(order[j] == 14) strcpy(item,"Butter");
                if(order[j] == 15) strcpy(item,"Eggs");
                if(order[j] == 16) strcpy(item,"Milk");
                if(order[j] == 17) strcpy(item,"Cheese");
                if(order[j] == 18) strcpy(item,"Yogurt");
                if(order[j] == 19) strcpy(item,"Onions");
                if(order[j] == 20) strcpy(item,"Garlic");
                if(order[j] == 21) strcpy(item,"Ginger");
                if(order[j] == 22) strcpy(item,"Tomato");
                if(order[j] == 23) strcpy(item,"Potato");
                if(order[j] == 24) strcpy(item,"Red Capcicum");
                if(order[j] == 25) strcpy(item,"Green Capcicum");
                if(order[j] == 26) strcpy(item,"Sugar");
                if(order[j] == 27) strcpy(item,"Salt");
                if(order[j] == 28) strcpy(item,"Pepper");
                if(order[j] == 29) strcpy(item,"Honey");
                if(order[j] == 30) strcpy(item,"Vinegar");


                printf("%s ------ > %dx  ------ > %.2f Taka\n", item, quantity[j], bill[j]);

                fopen(name,"a");
                fprintf(f,"%s ------ > %dx  ------ > %.2f Taka\n", item, quantity[j], bill[j]);

                fclose(f);

            }

            printf("Current total bill ------ > %.2f Taka (15%% VAT included)\n\n", total);

        }

        if(dc==2){

            count=0;
            for(int j=1;; j++){

                printf("Order #%d: ",j);
                scanf("%d", &order[j]);

                if(order[j] == 0) break;
                printf("Place Your quantity: ");
                scanf("%d", &quantity[j]);
                count++;


                o=menuP(order[j]);

                int p= o*quantity[j] ;
                bill[j] = p + (p*0.15);
                total = total - bill[j];
            }

            printf("\n");
            printf("Removed-\n");

            fopen(name,"a");
            fprintf(f,"\nRemoved-\n");

            fclose(f);

            for(int k=1; k<=count; k++){

                if(order[k] == 1) strcpy(item,"Rice");
                if(order[k] == 2) strcpy(item,"Wheat");
                if(order[k] == 3) strcpy(item,"Flour");
                if(order[k] == 4) strcpy(item,"Bread");
                if(order[k] == 5) strcpy(item,"Breakfast Cereal");
                if(order[k] == 6) strcpy(item,"Chicken");
                if(order[k] == 7) strcpy(item,"Beef");
                if(order[k] == 8) strcpy(item,"Mutton");
                if(order[k] == 9) strcpy(item,"Ilish");
                if(order[k] == 10) strcpy(item,"Tuna Can");
                if(order[k] == 11) strcpy(item,"Soybean Oil");
                if(order[k] == 12) strcpy(item,"Mustard Oil");
                if(order[k] == 13) strcpy(item,"Olive Oil");
                if(order[k] == 14) strcpy(item,"Butter");
                if(order[k] == 15) strcpy(item,"Eggs");
                if(order[k] == 16) strcpy(item,"Milk");
                if(order[k] == 17) strcpy(item,"Cheese");
                if(order[k] == 18) strcpy(item,"Yogurt");
                if(order[k] == 19) strcpy(item,"Onions");
                if(order[k] == 20) strcpy(item,"Garlic");
                if(order[k] == 21) strcpy(item,"Ginger");
                if(order[k] == 22) strcpy(item,"Tomato");
                if(order[k] == 23) strcpy(item,"Potato");
                if(order[k] == 24) strcpy(item,"Red Capcicum");
                if(order[k] == 25) strcpy(item,"Green Capcicum");
                if(order[k] == 26) strcpy(item,"Sugar");
                if(order[k] == 27) strcpy(item,"Salt");
                if(order[k] == 28) strcpy(item,"Pepper");
                if(order[k] == 29) strcpy(item,"Honey");
                if(order[k] == 30) strcpy(item,"Vinegar");


                printf("%s ------ > %dx  ------ > -%.2f Taka\n", item, quantity[k], bill[k]);

                f=fopen(name,"a");
                fprintf(f,"%s ------ > %dx  ------ > -%.2f Taka\n", item, quantity[k], bill[k]);

                fclose(f);

            }

            printf("Current total bill ------ > %.2f Taka (15%% VAT included)\n\n", total);

        }

        if(dc==3){

            printf("Final bill ------ > %.2f Taka (15%% VAT included)\n\n\n", total);

            f=fopen(name,"a");
            fprintf(f,"\nFinal bill ------ > %.2f Taka (15%% VAT included)\n\n", total);

            fclose(f);

            printf("               Money Receipt\n           .....................\n\n");

            f=fopen(name,"r");

            while((memo=fgetc(f))!=EOF){

                printf("%c",memo);
            }

            fclose(f);
            break;

        }

    }

}
