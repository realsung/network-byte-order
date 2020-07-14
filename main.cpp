#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "byte_order.h"

int main(int argc,char *argv[]){
    if(argc < 3){
        printf("syntax : %s <file1> <file2>\n",argv[0]);
        exit(-1);
    }

    uint32_t n1, n2;
    FILE *fp1 = fopen(argv[1],"r");
    FILE *fp2 = fopen(argv[2],"r");
    
    fread(&n1,sizeof(uint32_t),1,fp1);
    fread(&n2,sizeof(uint32_t),1,fp2);
    n1 = byte_order(n1);
    n2 = byte_order(n2);

    printf("%d(%#x) + %u(%#x) = %u(%#x)\n",n1,n1,n2,n2,n1+n2,n1+n2);
    // 1000(0x3e8) + 500(0x1f4) = 1500(0x5dc)



    
    return 0;
}