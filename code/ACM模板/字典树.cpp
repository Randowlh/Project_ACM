void append(char *s){
	char *p = s;
	int t = 1, id; // t = 0 is also OK
	for(; *p; ++p){
		id = *p - 97;
		t = d[t][id] ? d[t][id] : (d[t][id] = ++V);
	}
	++val[t];
}

// the process of matching is just like going on a DFA, so omit it.