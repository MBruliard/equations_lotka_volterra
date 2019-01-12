CFLAGS = -g -Wall
headerfiles = euler_exp.h systemeLV.h runge_kutta4.h


all: ApproxLoktaVolterra.exe TestAffichageEulerExplKokh.exe TestAffichageEulerExplSimple.exe TestAffichageEulerExplParam.exe TestAffichageRungeKutta4Param.exe

default : ResEulerExplLV.exe


#fichiers .o
euler_exp.o: euler_exp.c ${headerfiles}
	gcc ${CFLAGS} -c euler_exp.c

runge_kutta4.o: runge_kutta4.c ${headerfiles}
	gcc ${CFLAGS} -c runge_kutta4.c

systemeLV.o: systemeLV.c systemeLV.h
	gcc ${CFLAGS} -c systemeLV.c

main.o: main.c ${headerfiles}
	gcc ${CFLAGS} -c main.c

#fichiers .exe
ApproxLoktaVolterra.exe : main.o systemeLV.o euler_exp.o runge_kutta4.o ${headerfiles}
	gcc ${CFLAGS} main.o systemeLV.o euler_exp.o runge_kutta4.o -o ApproxLoktaVolterra.exe 


#fichiers test
test_affichage_EulerExplKokh.o: test_affichage_EulerExplKokh.c ${headerfiles}
	gcc ${CFLAGS} -c test_affichage_EulerExplKokh.c

test_affichage_EulerExplSimple.o: test_affichage_EulerExplSimple.c ${headerfiles}
	gcc ${CFLAGS} -c test_affichage_EulerExplSimple.c

TestAffichageEulerExplKokh.exe: test_affichage_EulerExplKokh.o systemeLV.o euler_exp.o ${headerfiles}
	gcc ${CFLAGS} test_affichage_EulerExplKokh.o systemeLV.o euler_exp.o -o TestAffichageEulerExplKokh.exe

TestAffichageEulerExplSimple.exe: test_affichage_EulerExplSimple.o systemeLV.o euler_exp.o ${headerfiles}
	gcc ${CFLAGS} test_affichage_EulerExplSimple.o systemeLV.o euler_exp.o -o TestAffichageEulerExplSimple.exe

test_affichage_EulerExplParam.o: test_affichage_EulerExplParam.c ${headerfiles}
	gcc ${CFLAGS} -c test_affichage_EulerExplParam.c	

TestAffichageEulerExplParam.exe: test_affichage_EulerExplParam.o systemeLV.o euler_exp.o ${headerfiles}
	gcc ${CFLAGS} test_affichage_EulerExplParam.o systemeLV.o euler_exp.o -o TestAffichageEulerExplParam.exe

test_affichage_RungeKutta4Param.o: test_affichage_RungeKutta4Param.c ${headerfiles}
	gcc ${CFLAGS} -c test_affichage_RungeKutta4Param.c	

TestAffichageRungeKutta4Param.exe: test_affichage_RungeKutta4Param.o systemeLV.o runge_kutta4.o ${headerfiles}
	gcc ${CFLAGS} test_affichage_RungeKutta4Param.o systemeLV.o runge_kutta4.o -o TestAffichageRungeKutta4Param.exe
#commandes nettoyage
clean: 
	rm -fv *.o *.exe

clean_results:
	rm -fv *.dat




