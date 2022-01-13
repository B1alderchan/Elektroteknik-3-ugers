#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct data
{
    double time[2500];
    float temperature[2500];
    float voltage[2500];
    float current[2500];
    float added_effect[2500];
    float toven[2500];                          // Teoretisk temperatur af ovnen
    int rows;
    
};
void menu(struct data *oven);
void backtomenu(struct data *oven);
void load (struct data *oven);
void print (struct data *oven);
void added_effect(struct data *oven);
void temperature();
void parameters();

int main()
{
    struct data oven, *poven;
    poven = &oven;

    menu(poven);

    return (0);
}

void menu(struct data *oven)
{
    int user;
    printf("\n-------MENU------\n\n");
    printf("1. Print file\n");
    printf("2. Calculate added effect\n");
    printf("3. Calculate theoretical temperature\n");
    printf("4. Calculate parameters\n");
    printf("5. Terminator\n\n");
    printf("Enter your choice: ");
    scanf("%d",&user);

    if (user == 1)
    {
        load(oven);
        print(oven);
        backtomenu(oven);
    }
    else if (user == 2)
    {
        load(oven);
        added_effect(oven);
        backtomenu(oven);
    }
    else if (user == 3)
    {
        temperature();
        backtomenu(oven);
    }
    else if (user == 4)
    {
        parameters();
        backtomenu(oven);
    }
    else if (user == 5)
    {
        exit(0);
    }
}
void backtomenu(struct data *oven)
{
    int back;
    printf("\n\nPress 5 to return to menu: ");
    scanf("%d",&back);
    if(back == 5)
    {
        menu(oven);
    }
}
void load (struct data *oven)
{
    FILE *fp;
    fp = fopen("ovntest.csv", "r");

    int i = 0;

    while (1)                           
    {
        fscanf(fp, "%lf,", &oven->time[i]);       
        if (oven->time[i] > 0)            
        {
            fscanf(fp, "%f,%f,%f,", &oven->temperature[i], &oven->voltage[i], &oven->current[i]);         
        }
        else        
        {
            break;
        }
        i++;                                                           
    }
    fclose(fp);
    oven->rows = i;
}
void print (struct data *oven)
{
    for (int i = 0; i < oven->rows; i++)
    {
        printf("%0.10lf, %f, %f, %f\n", oven->time[i], oven->temperature[i], oven->voltage[i], oven->current[i]);
    }
}

void added_effect(struct data *oven)
{
    for (int i = 0; i < oven->rows; i++)
    {
        oven->added_effect[i] = oven->voltage[i] * oven->current[i];
        printf("%f\n", oven->added_effect[i]);
    }
    //for 
}
void temp_oven()
{

}
void parameters()
{


}
