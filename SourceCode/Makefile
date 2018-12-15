
output: Main.o EvaluatorOfScheduler.o JobQueue.o HugeJobQueue.o LargeJobQueue.o MediumJobQueue.o ShortJobQueue.o Input.o User.o ITStaff.o Researcher.o Student.o Job.o Node.o Output.o Scheduler.o Test.o UsersGenerator.o
	g++ Main.o EvaluatorOfScheduler.o JobQueue.o HugeJobQueue.o LargeJobQueue.o MediumJobQueue.o ShortJobQueue.o Input.o User.o ITStaff.o Researcher.o Student.o Job.o Node.o Output.o Scheduler.o Test.o UsersGenerator.o -o simulationOutput

Main.o: *.cpp *.h
	g++ -c Main.cpp

EvaluatorOfScheduler.o: *.cpp *.h
	g++ -c EvaluatorOfScheduler.cpp

JobQueue.o: *.cpp *.h
	g++ -c JobQueue.cpp

HugeJobQueue.o: *.cpp *.h
	g++ -c HugeJobQueue.cpp

LargeJobQueue.o: *.cpp *.h
	g++ -c LargeJobQueue.cpp

MediumJobQueue.o: *.cpp *.h
	g++ -c MediumJobQueue.cpp

ShortJobQueue.o: *.cpp *.h
	g++ -c ShortJobQueue.cpp

Input.o: *.cpp *.h
	g++ -c Input.cpp

User.o: *.cpp *.h
	g++ -c User.cpp

ITStaff.o: *.cpp *.h
	g++ -c ITStaff.cpp

Researcher.o: *.cpp *.h
	g++ -c Researcher.cpp

Student.o: *.cpp *.h
	g++ -c Student.cpp

Job.o: *.cpp *.h
	g++ -c Job.cpp

Node.o: *.cpp *.h
	g++ -c Node.cpp

Output.o: *.cpp *.h
	g++ -c Output.cpp

Scheduler.o: *.cpp *.h
	g++ -c Scheduler.cpp

Test.o: *.cpp *.h
	g++ -c Test.cpp

UsersGenerator.o: *.cpp *.h
	g++ -c UsersGenerator.cpp

clean:
	rm *.o output
