all:
	g++ main.cpp tokenizer.cpp state_transitions.cpp DatalogProgram.cpp Parameter.cpp Predicate.cpp Rule.cpp Relation.cpp Tuple.cpp -o lab3
project:
	g++ project_test.cpp Relation.cpp Tuple.cpp -o lab3_project
rename:
	g++ rename_test.cpp Relation.cpp Tuple.cpp -o lab3_rename
select:
	g++ select_test.cpp Relation.cpp Tuple.cpp -o lab3_select