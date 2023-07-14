#include "BelugaMinimal.h"
#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaStringTest, "Beluga.String", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaStringTest::RunTest(const FString& Parameters)
{
	// 생성, 대입
	{
		FString strChar("char");
		FString strWChar(L"wchar");
		FString strTChar(TEXT("wchar"));

		strChar = "char";
		strWChar = "wchar";
		strTChar = TEXT("wchar");
	}

	// 대입 연산자 =
	

	// Printf
	{
		TestEqual(TEXT("Printf"), FString::Printf(TEXT("%d %f %s"), 123, 1.0f, TEXT("string")), TEXT("123 1.000000 string"));
	}

	// Format
	{
		{
			FStringFormatNamedArguments NamedArgs;
			NamedArgs.Add(TEXT("First"), 123);
			NamedArgs.Add(TEXT("Second"), 1.0f);
			NamedArgs.Add(TEXT("Third"), TEXT("string"));

			TestEqual(TEXT("FormatNamedArguments"), FString::Format(TEXT("{First} {Second} {Third}"), NamedArgs), TEXT("123 1.000000 string"));
		}
		
		{
			FStringFormatOrderedArguments OrderedArgs;
			OrderedArgs.Add(123);
			OrderedArgs.Add(1.0f);
			OrderedArgs.Add(TEXT("string"));
			
			TestEqual(TEXT("FormatOrderedArgs"), FString::Format(TEXT("{0} {1} {2}"), OrderedArgs), TEXT("123 1.000000 string"));
		}
	}

	// operator []

	// 대소비교
	{
		FString String1 = TEXT("a");
		FString String2 = TEXT("b");

		int32 CompareResult = String1.Compare(String2);

		TestTrue(TEXT("Coampare 1"), CompareResult < 0);
		// String 1(기준 대상)과 String 2(비교 대상)의 사전상의 순서를 비교하여 String 1이 더 앞에 있다면 -1을, 더 뒤에 있다면 +1을, 같다면 0을 반환한다.
	}

	// TCHAR* 얻기
	{
		FString MyString = TEXT("My String is 'My'");
		const TCHAR* MyCharPointer = *MyString;

		TestEqual(TEXT("Mystring "), MyCharPointer, L"My String is 'My'");
	}

	// Replace
	{
		FString str("asdf");
		FString result = str.Replace(TEXT("sd"), TEXT("ds"));
		check(result == TEXT("adsf"));
	}

	// 길이 구하기
	{
		FString str(TEXT("string"));
		int32 LenStr = str.Len();
		check(LenStr == 6);

		//UE_LOG(LogBelluga);
	}


	// Operators
	{
		FString strApple(TEXT("Apple"));
		FString strBanana(TEXT("Banana"));

		// []
		{
			TestEqual(TEXT("Operator []"), strApple[0], L'A');
		}

		// < >
		{
			TestTrue(TEXT("Operator <"), strApple < strBanana);
		}
	}

	// Insert

	// InsertAt
	{
		FString str(TEXT("My name is"));
		str.InsertAt(10, TEXT(" Donggil"));

		TestEqual(TEXT("Insert "), str, L"My name is Donggil");
	}

	// clear (Empty ?)
	{
		FString str(TEXT("Hi"));
		str.Empty();

		TestEqual(TEXT("Empty "), str, L"");
	}

	// isEmpty
	{
		FString str(TEXT("My name"));
		int32 CheckingIsEmpty;
		if (str.IsEmpty())
			CheckingIsEmpty = 1;
		else CheckingIsEmpty = 0;

		TestEqual(TEXT("isEmpty"), CheckingIsEmpty, 0);
	}

	// Shrink
	{
		FString str(TEXT("Hello"));
		str.Reserve(100);

		int32 Reserved = str.GetAllocatedSize();

		str.Shrink();

		int32 Shrinked = str.GetAllocatedSize();

		TestTrue(TEXT("Shink"), Reserved != Shrinked);
	}

	// RemoveAt
	{
		FString str(TEXT("Donggil is GooD"));
		str.RemoveAt(12, 2);

		TestEqual(TEXT(""), str, L"Dongil is GD");
	}

	// find 로 인덱스 
	{

	}

	// Left
	{
		FString str(TEXT("qwerasdf"));
		FString out = str.Left(4);
		check(out == TEXT("qwer"))
	}
	// Mid
	{
		FString str(TEXT("qwerasdf"));
		FString out = str.Mid(3);
		check(out == TEXT("rasdf"))
	}
	// Right
	{
		FString str(TEXT("qwerasdf"));
		FString out = str.Right(3);
		check(out == TEXT("sdf"))
	}

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaNameTest, "Beluga.Name", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaNameTest::RunTest(const FString& Parameters)
{
	return true;
}