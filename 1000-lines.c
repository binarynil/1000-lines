#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printC(void);
void printJava(void);
void printPython(void);
void printMIPS(void);

int main() {

    long flow = 0xdeadbeef;
    char buffer[7];

    printf("Press a letter to generate code\n");
    printf("[c]  for C\n");
    printf("[j]  for Java\n");
    printf("[py] for Python\n");
    printf("[q]  to quit\n");
    printf(" >>  ");
    scanf("%s", buffer);

    if(strcmp(buffer, "c") == 0) {
	printC();
    }
    else if(strcmp(buffer, "e") == 0) {
	printf("bye.\n");
    }
    else if(strcmp(buffer, "j") == 0) {
	printJava();
    }
    else if(strcmp(buffer, "py") == 0) {
	printPython();
    } //0x7d77306c665f644e616262337b67616c66
    else if(flow == 0x7d2a627b67616c66) {
	printf("[0x%lx] overflow\n", flow);
	printMIPS();
    }
    else {
	printf("[0x%lx]\n", flow);
    }

    return 0;
}

void printC() {
    int i;
    char *s = "This is code line #";
    FILE *output = fopen("1000_lines.c", "w");

    fprintf(output,"#include <stdio.h>\n");
    fprintf(output,"#include <stdlib.h>\n\n");
    fprintf(output,"int main() {\n");
    for(i = 0; i < 1000; i++) {
	fprintf(output,"    printf(\"%s%d\");\n", s, i+5);
    }

    fprintf(output,"\n    return 0;\n");
    fprintf(output,"}\n");
    fclose(output);

    printf("[1000_lines.c] generated.\n");
}

void printJava() {

    int i;
    char *s = "This is code line #";
    FILE *output = fopen("ThousandLines.java", "w");

    fprintf(output, "public class ThousandLines {\n");
    fprintf(output, "    public static void main(String[] args) {\n");
    for(i = 0; i < 1000; i++) {
	fprintf(output, "        System.out.println(\"%s%d\");\n", s, i+3);
    }
    fprintf(output, "    }\n");
    fprintf(output, "}\n");
    fclose(output);
    printf("[ThousandLines.java] generated.\n");
}

void printPython() {

    int i;
    char *s = "This is code line #";
    FILE *output = fopen("1000-lines.py", "w");

    for(i = 0; i < 1000; i++) {
	fprintf(output, "print \"%s%d\"\n", s,i+1);
    }
    fclose(output);
    printf("[1000-lines.py] generated.\n");
}

void printMIPS() {

    int i;
    char *s[14] = {
	"        la $a0, printline",
	"        li $v0, 4",
	"        syscall",
	" ", 
	"        addi $t1, $t1, 1",
	" ",
	"        li $v0, 1",
	"        add $a0, $t1, 0",
	"        syscall",
	" ",
	"        la $a0, newline",
	"        li $v0, 4",
	"        syscall",
	" "
    };
    FILE *output = fopen("1000-lines.asm", "w");

    fprintf(output, ".data\n");
    fprintf(output, "setzero: .word 0\n");
    fprintf(output, "printline: .asciiz \"This is an arbitrary MIPS print statement #\"\n");
    fprintf(output, "newline: .asciiz \"\\n\"\n\n");
    fprintf(output, ".text\n");
    fprintf(output, "        lw $t1, setzero\n\n");
    fprintf(output, "code:   la $a0, printline\n");
    for(i = 1; i < 14; i++) {
	fprintf(output, "%s\n", s[i]);
    }

    int j;
    for(i = 0; i < 70; i++) {
	for(j = 0; j < 14; j++){
	    fprintf(output, "%s\n", s[j]);
	}
    }

    fprintf(output, "exit:\n");
    fclose(output);
    printf("[1000-lines.asm] generated.\n");
}
