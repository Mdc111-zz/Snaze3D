#ifndef ScoreH /* Include guard */
#define ScoreH

class Score {
public:
	GLint points = 0;
	void WriteToScreen(char *string);
	void UpdateScore();
};


#endif