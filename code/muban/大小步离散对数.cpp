int Boy_Step_Girl_Step(){
	mii :: iterator it;
	ll boy = 1, girl = 1, i, t;
	for(i = 0; i < B; i++){
		m.insert(pr((int)boy, i)); // if there exists in map, then ignore it
		(boy *= a) %= p;
	}
	for(i = 0; i * B < p; i++){
		t = b * inv(girl) % p;
		it = m.find((int)t);
		if(it != m.end())
			return i * B + it->second;
		(girl *= boy) %= p;
	}
	return -1;
} 

// input p and then B = (int)sqrt(p - 1);
// inv(x) is the multiplicative inverse of x in Z[p].
// mii: map <int, int> and m is a variable of which.