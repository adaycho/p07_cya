p07_nfa_analyzer: client_p07.cc nfa.cc transition.cc state.cc language.cc chain.cc alphabet.cc symbol.cc
	g++ -o p07_nfa_analyzer client_p07.cc nfa.cc transition.cc state.cc language.cc chain.cc alphabet.cc symbol.cc

clean:
	rm -rf *.out p07_nfa_analyzer
