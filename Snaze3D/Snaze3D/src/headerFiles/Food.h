#ifndef FOODHEADER   /* Include guard */
#define FOODHEADER

class Food {
public:
	GLint foodXPosition = 0;
	GLint foodYPosition = 0;
	void DrawFood();
	void NewFood(int leftBound, int botBound);
};
#endif // FOO_H_