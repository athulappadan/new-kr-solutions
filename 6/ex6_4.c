#include <stdio.h>
#include <ctype.h>

#define MAXWORD	100
#define NDISTINCT 1000

struct tnode {
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *addtree(struct tnode*, char *);
int get_word(char *, int);
void sortlist(void);
void treestore(struct tnode *);

struct tnode *list[NDISTINCT];
int ntn = 0;

main()
{
	struct tnode *root;
	int i;
	char word[MAXWORD];

	root = NULL;
	while (get_word(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			root = addtree(root, word);

	treestore(root);
	sortlist();
	for(i = 0; i < ntn; i++)
		printf("%2d:%20s\n", list[i]->count, list[i]->word);
	return 0;
}

struct tnode *talloc(void);
char *strd_up(char *);

struct tnode *addtree(struct tnode *p, char *w)
{
        int cond;

        if (p == NULL) {
                p = talloc();
                p->word = strd_up(w);
                p->count = 1;
                p->left = p->right = NULL;
        } else if ((cond = strcmp(w, p->word)) == 0)
                p->count++;
        else if (cond < 0)
                p->left = addtree(p->left, w);
        else
                p->right = addtree(p->right, w);
        return p;
}

struct tnode *talloc(void)
{
        return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strd_up(char *s)
{
        char *p;

        p = (char *) malloc(strlen(s) + 1);
        if (p != NULL)
                strcpy(p, s);
        return p;
}

void treestore(struct tnode *p)
{
	if (p != NULL) {
		treestore(p->left);
		if (ntn < NDISTINCT)
			list[ntn++] = p;
		treestore(p->right);
	}
}

void sortlist(void)
{
	int gap, i, j;
	struct tnode *temp;

	for(gap = ntn/2; gap > 0; gap /= 2)
		for (i = gap; i < ntn; i++)
			for (j = i - gap; j >= 0; j++) {
				if ((list[j]->count) >= (list[j+gap]->count))
					break;
				temp = list[j];
				list[j] = list[j+gap];
				list[j+gap] = temp;
			}
}


