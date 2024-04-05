/* 
单实例模式

只返回一个类
 */
class Singleton
{
private:
	static Singleton * pInstance;
    Singleton() {};
public:
	static Singleton * GetInstance()
	{
		if (pInstance == nullptr)
			pInstance = new Singleton();
		return pInstance;
	}
};
Singleton * Singleton::pInstance = nullptr;

int main(void)
{
    class Singleton *A = Singleton::GetInstance();
    class Singleton *B = Singleton::GetInstance();

    return 0;
}