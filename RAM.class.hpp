#ifndef RAM_H
#define RAM_H

class RAM {
	public:
		RAM(void);
		RAM(const RAM& copy);
		~RAM(void);
		RAM& operator=(const RAM&);
};

#endif
