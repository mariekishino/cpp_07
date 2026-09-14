// メンバ関数を持たない場合

#include <iostream>

template <typename T>
class vector2d
{
	public:
		// テンプレートがパラメータで渡された型でメンバ変数を宣言
		T x;
		T y;
};

void show(int v)
{
	std::cout << "int: " << v << std::endl;
}
void show(float v)
{
	std::cout << "float: " << v << std::endl;
}

int main()
{
	// float型の２次元ベクトルを定義
	vector2d<float> f2d{10.0f, 20.0f};

	// int型の２次元ベクトルを定義
	vector2d<int> i2d{10, 20};

	// エラー。同じクラステンプレートを使っているが、テンプレート引数が異なるので別の型
	// i2d = 2fd;

	f2d.x = -10.0f; //　メンバへのアクセス方法は通常のクラスと同じ

	show(i2d.y); // int型のオーバーロードが呼ばれる
	show(f2d.y); // float型のオーバーロードが呼ばれる
}



