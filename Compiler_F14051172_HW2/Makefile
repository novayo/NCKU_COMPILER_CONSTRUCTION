CC=gcc
YFLAG=-d -v
FNAME=compiler_hw2
EXE=myparser

compile: scanner parser
	${CC} lex.yy.c y.tab.c -o ${EXE}

scanner:
	lex ${FNAME}.l

parser: 
	yacc ${YFLAG} ${FNAME}.y

test0: compile
	./${EXE} < input/zero_error.c

test1: compile
	./${EXE} < input/syntactic_error.c

test2: compile
	./${EXE} < input/semantic_error.c

clean:
	rm ${EXE} y.tab* lex.* y.output

