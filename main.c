#include <stdio.h>
#include <string.h>

int main() {
    FILE *file;
    char line[1024];
    char *open_str = "Linux version 5.10.190";
    char *close_str = "Elead machine Poweroff";
    long line_num = 0;
    int open_count = 0;

    // 打開文件進行讀取
    file = fopen("COM36.log", "r");

    if (file == NULL) {
        printf("無法打開文件。\n");
        return 1;
    }

    // 使用 fgets 逐行讀取文件內容，直到文件結束
    while (fgets(line, sizeof(line), file) != NULL) {
            line_num++;
	    //printf("%s\n", line);

	    char *ret = strstr(line, open_str);
	    if(ret != NULL)
	    {
	    	open_count++;
		if(open_count > 1)
		{
			printf("line num: %ld\n", line_num);
			open_count = 0;
		}
	    }

	    ret = strstr(line, close_str);
	    if(ret != NULL && open_count != 0)
	    {
		open_count--;
	    }
	    
    }

    printf("finish\n");

    // 關閉文件
    fclose(file);

    return 0;
}
