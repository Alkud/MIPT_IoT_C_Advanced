#include "program_arguments.h"

void PrintHelp()
{
    printf("Поиск площади, образованной графиками трёх функций\n");
    printf("Аргументы командной строки:\n");
    printf("\t-h       вывод справки\n");
    printf("\t-r       eps1 - точность поиска корней\n");
    printf("\t-i       eps2 - точность численного интегрирования\n");
    printf("\t-t       режим тестирования\n");
    printf("\t-a       левая граница для режима тестирования\n");
    printf("\t-b       левая граница для режима тестирования\n");
}

int ParseArguments(const int argc, char* argv[], ProgramArguments* arguments)
{
    int need_help = 0;
    int opt;
    if (argc < 2) {
        return 1;
    }
    while ( (opt = getopt(argc,argv,":hr:i:t")) != -1){
        switch (opt){
            case 'h':
                return 1;
            break;
            case 'r':
                sscanf(optarg, "%lf", &arguments->eps1);
                break;
            case 'i':
                sscanf(optarg, "%lf", &arguments->eps2);
                break;
            case 't':
                arguments->test_mode = 1;
                break;
            case 'a':
                sscanf(optarg, "%lf", &arguments->test_a);
                break;
            case 'b':
                sscanf(optarg, "%lf", &arguments->test_b);
                break;
            case ':':
                printf("Ошибка! Опция -%c требует значения\n\n", optopt);
                need_help = 1;
            case '?':
                printf("Ошибка! Неизвестная опция -%c\n\n", optopt);
            need_help = 1;
            default:
                break;
        };
    };
    if (arguments->eps1 <= 0 || arguments->eps2 <= 0) {
        printf("Ошибка! Точность должна быть положительным числом (больше 0)\n");
        need_help = 1;
    }
    return need_help;
}