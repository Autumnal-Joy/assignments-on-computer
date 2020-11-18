// ������ջ�Ľڵ�
typedef struct _num_node {
    // ������
    double num;
    // ��һ���ڵ�
    _num_node* nextNode;
} NumNode;

// ������ջ�Ľڵ�
typedef struct _ope_node {
    // ������
    char ope;
    // ��һ���ڵ�
    _ope_node* nextNode;
} OpeNode;

/*
    @param {char*} pstr: ��ȡ�û��������'='��β���ַ���, �����ڴ˵�ַ, ��ౣ��99����Ч�ַ�(�����հ��ַ�)
*/
void getUserInput(char* pstr);

/*
    @param {char*} pstr: �û�����ı��ʽ�ַ�����ַ
    @return {double}: ������

    ��Ҫһ��������ջ��һ��������ջ
    ѭ����ȡ�ַ�����һ���������������
        ���ǲ�����, ��ֱ��ѹ���������ջ
        ���ǲ�����, ��ʼ����
            ���˲�������������, ��ֱ��ѹ���������ջ
            ���˲�������������, �򲻶ϵ���������, ֱ������������Ϊֹ
                ���ǵ�Ŀ�Ĳ�����, �򵯳�һ����������,�����ڲ������ϲ�ѹ���������ջ
                ����˫Ŀ�Ĳ�����, �򵯳�����������, ����"�ȵ��� ������ �󵯳�"��˳���������ѹ�ز�������ջ
            ���˲����������ڼ���
                ��ջ�������������ȼ���С�ڴ˲�����, �򲻶ϵ���������, ֱ������������
                    ����, �����ĵ�Ŀ��˫Ŀ��������ͬ������Ӳ�������ջ��ȡ����, ����������ѹ�ز�������ջ
                ���������ǵȺ�, ˵�����ʽ��ȡ����β��, ��ʱ�˳�ѭ��, ����Ѵ˲�����ѹ���������ջ
    ��ʱ��������ջ�����ҽ���һ��������
    �ͷ�ջ���ڴ��, ���˲���������
*/
double calculate(char* pstr);

/*
    @param {char*} pstr: �û�����ı��ʽ�ַ�����ַ

    ��ȡ������'-'�ı�Ϊ'~', ����'-'����
*/
void preProcess(char* pstr);

/*
    @param {char*} pstr: ���ʽ�ַ�����ַ
    @param {char*} isNum: �����char���ͱ����ĵ�ַ, ���ڷ����������߷���ֵ�ǲ��������ǲ�����, �޸�ָ��λ�õ�char���ͱ�����ֵΪ0��1
    @return {int} ������һ����������������Ķ�Ӧ�ַ�

    ���徲̬����loc, ��¼��ȡ����ʼλ��, ��ʼΪ0
    ��locλ�ÿ�ʼ��ȡ��һ���������������, �޸�loc��ֵ��isNumָ��ָ���char���ͱ�����ֵ��, �������������������𷵻�
    ����Ĳ�����, �ö�Ӧ�ĵ��ַ��������ڵ�
    ������'\0'ʱ, loc��������, *isNum����, ����'='
*/
char nextOneIsNum(char* pstr, char* nextOpe, double* nextNum);

/*
    ���ȼ�0:
    '(': �����ŷ����,
    '=': ���ʽĩβ�Ⱥ�,
    ���ȼ�1:
    '+': ˫Ŀ�ӷ������,
    '-': ˫Ŀ���������,
    ���ȼ�2:
    '*': ˫Ŀ�˷������,
    '/': ˫Ŀ���������,
    '~': ��Ŀȡ�������,
    ���ȼ�3:
    '^': ˫Ŀ�˷������,
    ���ȼ�4:
    's': ��Ŀ���������,
    'c': ��Ŀ���������,
    't': ��Ŀ���������,
    'o': ��Ŀ���������,
    'g': ��Ŀ���ö��������,
    'n': ��Ŀ��Ȼ���������,

    @param {char} ope: ������ope
    @return {int}: �����������ȼ�
*/
int checkPriority(char ope);

/*
    @param {char*} p: ��һ����������ʼ���ַ����ĵ�ַ
    @return {char}: ��������Ӧ���ַ�

    ���ַ��Ĳ�����ת��Ϊ��Ӧ���ַ��󷵻�
        'sin': 's'
        'cos': 'c'
        'tan': 't'
        'cot': 'o'
        'lg': 'g'
        'ln': 'n'
*/
char getType(char* p);

/*
    @param {char} ope: ������
    @param {NumNode*} numStack: ���������ڵ�ջ

    ���ǵ�Ŀ�Ĳ�����, ��Ӳ�������ջ�е���һ��������, �������������ڲ������ϲ�ѹ���������ջ
    ����˫Ŀ�Ĳ�����, �򵯳�����������, ����"�ȵ��� ������ �󵯳�"��˳���������ѹ�ز�������ջ
*/
double getValue(char ope, NumNode* numStack);

/*
    @return {NumNode*}: ���ز�����ջ�ı�ͷ
*/
NumNode* createNumStack(void);

/*
    @return {OpeNode*}: ���ز�����ջ�ı�ͷ
*/
OpeNode* createOpeStack(void);

/*
    @param {double} num: ����һ���������ڵ������������num
    @return {NumNode*}: ���ش����Ĳ������ڵ��ַ
*/
NumNode* createNumNode(double num);

/*
    @param {char} ope: ����һ���������ڵ������������ope
    @return {OpeNode*}: ���ش����Ĳ������ڵ��ַ
*/
OpeNode* createOpeNode(char ope);

/*
    @param {OpeNode*} stack: �ܵ������Ĳ�����ջ
    @param {char} ope: ��ѹ��ջ�Ĳ�����
*/
void pushOpe(OpeNode* stack, char ope);

/*
    @param {NumNode*} stack: �յ������Ĳ�����ջ
    @param {double} num: ��ѹ��ջ�Ĳ�����
*/
void pushNum(NumNode* stack, double num);

/*
    @param {NumNode*} stack: �ܵ������Ĳ�����ջ
    @return {char}: ջ�Ƿ��, ����0��1
*/
char isNumStackEmpty(NumNode* stack);

/*
    @param {NumNode*} stack: �ܵ������Ĳ�����ջ
    @return {char}: ջ�Ƿ��, ����0��1
*/
char isOpeStackEmpty(OpeNode* stack);

/*
    @param {NumNode*} stack: �ܵ������Ĳ�����ջ
    @return {double}: �Ӳ�����ջ�е����Ĳ�����, ��ջ�ѿ��򷵻�0
*/
double popNum(NumNode* stack);

/*
    @param {OpeNode*} stack: �ܵ������Ĳ�����ջ
    @return {char}: �Ӳ�����ջ�е����Ĳ�����, ��ջ�ѿ��򷵻�0
*/
char popOpe(OpeNode* stack);

/*
    @param {NumNode*} stack: �ܵ������Ĳ�����ջ
    @return {double}: ������ջ��Ԫ��, ��ջ�ѿ��򷵻�0
*/
double topNum(NumNode* stack);

/*
    @param {OpeNode*} stack: �ܵ������Ĳ�����ջ
    @return {char}: ������ջ��Ԫ��, ��ջ�ѿ��򷵻�0
*/
char topOpe(OpeNode* stack);

/*
    @param {NumNode*} stack: �ܵ������Ĳ�����ջ
*/
void deleteNumStack(NumNode* stack);

/*
    @param {OpeNode*} stack: �ܵ������Ĳ�����ջ
*/
void deleteOpeStack(OpeNode* stack);

/*
    ���Ų�ƥ��ʱ��������ֹ����
*/
void bracketsNotMatched(void);

/*
    ����0ʱ��������ֹ����
*/
void divideByZeroError(void);

/*
    ���ʽ�����Ϲ���ʱ��������ֹ����
*/
void illegalExpression(void);

/*
    �������ں�����������ʱ��������ֹ����
*/
void valueRangeError(void);

/*
    ����������ʱ��������ֹ����
*/
void operatorNameError(void);

