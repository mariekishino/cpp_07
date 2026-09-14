// 独習C++ p.417
// 関数テンプレートによるint/float演算

#include <iostream>
// この段階ではまだテンプレートパラメターのTは具体的な型が決まっていない
template <typename T>
T fused_multiply_add(T a, T b, T c) // 戻り値の型にも仮引数を与える
{
	T r = a * b + c;
	return r;
}

// // floatの積和演算
// float fused_multiply_add(float a, float b, float c)
// {
// 	// 関数の本体での計算は整数と全く同じ
// 	float r = a * b + c;
// 	return r;
// }

int main()
{
	// 関数テンプレートでintを実体化して呼び出し
	std::cout << fused_multiply_add<int>(1, 2, 3) << std::endl;

	// 関数テンプレートでfloatで実体化して呼び出し
	std::cout << fused_multiply_add<float>(1.23456f, 1.23456f, 1.23456f) << std::endl;

	// 関数テンプレートをdoubleで実体化して呼び出し
	std::cout << fused_multiply_add<double>(1.23456, 1.23456, 1.23456) << std::endl;

}

