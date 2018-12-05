/*
Link to frozen library: https://github.com/cesanta/frozen
*/

#include "frozen.c" // library to print and read json files
#include <string.h>
#include <stdio.h>

#define GET_VARIABLE_NAME(Variable) (#Variable)
#define TRUE 1
#define FALSE 0

char failures[2][100] = {"Nível de óleo baixo, você deve trocar o óleo e verificar se há vazamentos",
                       "falha no nível de bateria, posso agendar uma revisão?"};
float destiny_latitude = -8.0340303;
float destiny_longitude = -34.84558;
int is_parked = 1;
float consuption = 13.3;
float mileage = 25.3;
float position_latitude = -8.05;
float position_longitude = -34.86;
float total_mileage = 400;

void generateJson()
{
    FILE *fp = fopen("api.json", "w");
    struct json_out out = JSON_OUT_FILE(fp);
    json_printf(&out, "{\n");
    json_printf(&out, "\tcar_status : {\n");
    json_printf(&out, "\t\tfailures : { \n");
    json_printf(&out, "\t\t\tfailure_1 : %Q,\n", failures[0]);
    json_printf(&out, "\t\t\tfailure_2 : %Q\n", failures[1]);
    json_printf(&out, "\t\t}\n");
    json_printf(&out, "\t},\n");
    json_printf(&out, "\tdestiny_positions : {\n");
    json_printf(&out, "\t\tlatitude : %.2f,\n", destiny_latitude);
    json_printf(&out, "\t\tlongitude : %.2f\n", destiny_longitude);
    json_printf(&out, "\t},\n");
    json_printf(&out, "\tis_parked : %B,\n", is_parked);
    json_printf(&out, "\tlast_trip : {\n");
    json_printf(&out, "\t\tconsuption : %.2f,\n", consuption);
    json_printf(&out, "\t\tmiliage : %.2f\n", mileage);
    json_printf(&out, "\t},\n");
    json_printf(&out, "\tposition : {\n");
    json_printf(&out, "\t\tlatitude : %.2f,\n", position_latitude);
    json_printf(&out, "\t\tlongitude : %.2f\n", position_longitude);
    json_printf(&out, "\t},\n");
    json_printf(&out, "\ttotal_mileage : %.2f \n", total_mileage);
    json_printf(&out, "}\n");
    fclose(fp);
    return;
}

void changeVariable(char *variableName)
{
    if (strcmp(variableName, "car_status") == 0)
    {
        printf("Change failures_1/failures_2? : ");
        scanf("%s", variableName);
        if (strcmp(variableName, "failures_1") == 0)
        {
            printf("failure_1 : ");
            scanf("%99s ", failures[0]);
        }
        else if (strcmp(variableName, "failures_2") == 0)
        {
            printf("failure_2 : ");
            scanf("%s", failures[1]);
        }
    }
    else if (strcmp(variableName, "destiny_position") == 0)
    {
        printf("Change latitude or longitude? : ");
        scanf("%s", variableName);
        if (strcmp(variableName, "latitude") == 0)
        {
            printf("latitude : ");
            scanf("%f", &destiny_latitude);
        }
        else if (strcmp(variableName, "longitude") == 0)
        {
            printf("latitude : ");
            scanf("%f", &destiny_longitude);
        }
    }
    else if (strcmp(variableName, "is_parked") == 0)
    {
        printf("is_parked (1/0) : ");
        scanf("%d", &is_parked);
    }
    else if (strcmp(variableName, "last_trip") == 0)
    {
        printf("Change consuption or mileage? : ");
        scanf("%s", variableName);
        if (strcmp(variableName, "consuption") == 0)
        {
            printf("consuption : ");
            scanf("%f", &consuption);
        }
        else if (strcmp(variableName, "mileage") == 0)
        {
            printf("mileage : ");
            scanf("%f", &mileage);
        }
    }
    else if (strcmp(variableName, "position") == 0)
    {
        printf("Change latitude or longitude? : ");
        scanf("%s", variableName);

        if (strcmp(variableName, "latitude") == 0)
        {
            printf("latitude : ");
            scanf("%f", &position_latitude);
        }
        else if (strcmp(variableName, "longitude") == 0)
        {
            printf("longitude : ");
            scanf("%f", &position_longitude);
        }
    }
    else if (strcmp(variableName, "total_mileage") == 0)
    {
        printf("total_mileage : ");
        scanf("%f", &total_mileage);
    }
}

int isValidEntry(char *variableName)
{
    if (strcmp(variableName, "car_status") == 0)
    {
        return 1;
    }
    else if (strcmp(variableName, "failures") == 0)
    {
        return 1;
    }
    else if (strcmp(variableName, "is_parked") == 0)
    {
        return 1;
    }
    else if (strcmp(variableName, "last_trip") == 0)
    {
        return 1;
    }
    else if (strcmp(variableName, "consuption") == 0)
    {
        return 1;
    }
    else if (strcmp(variableName, "mileage") == 0)
    {
        return 1;
    }
    else if (strcmp(variableName, "position") == 0)
    {
        return 1;
    }
    else if (strcmp(variableName, "latitude") == 0)
    {
        return 1;
    }
    else if (strcmp(variableName, "longitude") == 0)
    {
        return 1;
    }
    else if (strcmp(variableName, "total_mileage") == 0)
    {
        return 1;
    }

    return 0;
}

int main()
{
    char jsonString[20];
    while (TRUE)
    {
        printf("Enter json variable (n to quit): ");
        scanf("%s", jsonString);
        if (strcmp(jsonString, "n") == 0)
        {
            break;
        }
        if (isValidEntry(jsonString))
        {
            changeVariable(jsonString);
            generateJson();
        }
        else
        {
            printf("Invalid entry \n");
        }
    }
    return 0;
}
