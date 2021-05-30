#pragma once
class characters {
public:
	virtual int activity();
	characters();
	~characters();
};
class nun : virtual public characters {
public:
	int activity();
	nun();
	~nun();
};
class devil : virtual public characters {
public:
	int activity();
	devil();
	~devil();
};