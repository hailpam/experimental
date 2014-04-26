SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc
DST_DIR = dist
TST_DIR = test
BIN_DIR = bin
LOG_DIR = logs

CC       = g++
CCFLAGS  = -I${INC_DIR}
LDFLAGS  = -lrt

TARGET   = file_reader
TEST     = test_file_reader
DIST	 = file_reader.a

TARGET1  = nd_product
TEST1    = test_nd_product
DIST1	 = nd_product.a

TARGET2  = http_scraper
TEST2    = test_http_scraper
DIST2	 = http_scraper.a

all: ${TARGET}.o ${TARGET1}.o ${TARGET2}.o distributable  ${TEST}.o ${TEST1}.o ${TEST2}.o ${TEST} ${TEST1} ${TEST2}

${TEST}: ${OBJ_DIR}/${TEST}.o ${OBJ_DIR}/${TARGET}.o
	$(CC) -o $@ $^ -L${DST_DIR} $(LDFLAGS)
	mv ${TEST} ${BIN_DIR}/

${TEST1}: ${OBJ_DIR}/${TEST1}.o ${OBJ_DIR}/${TARGET1}.o
	$(CC) -o $@ $^ -L${DST_DIR} $(LDFLAGS)
	mv ${TEST1} ${BIN_DIR}/

${TEST2}: ${OBJ_DIR}/${TEST2}.o ${OBJ_DIR}/${TARGET2}.o
	$(CC) -o $@ $^ -L${DST_DIR} $(LDFLAGS)
	mv ${TEST2} ${BIN_DIR}/

${TARGET}.o: ${SRC_DIR}/${TARGET}.cpp ${INC_DIR}/${TARGET}.h
	$(CC) -Wall -c $(CCFLAGS) $<
	mv *.o ${OBJ_DIR}/

${TARGET1}.o: ${SRC_DIR}/${TARGET1}.cpp ${INC_DIR}/${TARGET1}.h
	$(CC) -Wall -c $(CCFLAGS) $<
	mv *.o ${OBJ_DIR}/

${TARGET2}.o: ${SRC_DIR}/${TARGET2}.cpp ${INC_DIR}/${TARGET2}.h
	$(CC) -Wall -c $(CCFLAGS) $<
	mv *.o ${OBJ_DIR}/

${TEST}.o: ${TST_DIR}/${TEST}.cpp ${OBJ_DIR}/${TARGET}.o
	$(CC) -Wall -c $(CCFLAGS) $<
	mv *.o ${OBJ_DIR}/

${TEST1}.o: ${TST_DIR}/${TEST1}.cpp ${OBJ_DIR}/${TARGET1}.o
	$(CC) -Wall -c $(CCFLAGS) $<
	mv *.o ${OBJ_DIR}/

${TEST2}.o: ${TST_DIR}/${TEST2}.cpp ${OBJ_DIR}/${TARGET2}.o
	$(CC) -Wall -c $(CCFLAGS) $<
	mv *.o ${OBJ_DIR}/

distributable:
	ar -cvq ${DIST} ${OBJ_DIR}/${TARGET}.o
	mv *.a ${DST_DIR}/

clean:
	rm ${OBJ_DIR}/*.o
	rm ${DST_DIR}/*.a

cleantest: clean
	rm ${BIN_DIR}/${TEST}
	rm *.dat
	rm ${LOG_DIR}/*.log
	rm *.png

displayplot: plot
	eog times.png

runtest:
	valgrind --tool=memcheck --leak-check=yes --log-file=${TEST}-valgrind.log  -v ${BIN_DIR}/${TEST}
	mv ${TEST}-valgrind.log ${LOG_DIR}/
