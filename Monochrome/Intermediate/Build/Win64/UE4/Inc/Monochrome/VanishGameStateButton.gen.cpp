// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Monochrome/VanishGameStateButton.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVanishGameStateButton() {}
// Cross Module References
	MONOCHROME_API UClass* Z_Construct_UClass_AVanishGameStateButton_NoRegister();
	MONOCHROME_API UClass* Z_Construct_UClass_AVanishGameStateButton();
	MONOCHROME_API UClass* Z_Construct_UClass_AGameStateButtonBase();
	UPackage* Z_Construct_UPackage__Script_Monochrome();
// End Cross Module References
	void AVanishGameStateButton::StaticRegisterNativesAVanishGameStateButton()
	{
	}
	UClass* Z_Construct_UClass_AVanishGameStateButton_NoRegister()
	{
		return AVanishGameStateButton::StaticClass();
	}
	struct Z_Construct_UClass_AVanishGameStateButton_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AVanishGameStateButton_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameStateButtonBase,
		(UObject* (*)())Z_Construct_UPackage__Script_Monochrome,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVanishGameStateButton_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "VanishGameStateButton.h" },
		{ "ModuleRelativePath", "VanishGameStateButton.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AVanishGameStateButton_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVanishGameStateButton>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AVanishGameStateButton_Statics::ClassParams = {
		&AVanishGameStateButton::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AVanishGameStateButton_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AVanishGameStateButton_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AVanishGameStateButton()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AVanishGameStateButton_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AVanishGameStateButton, 2160872605);
	template<> MONOCHROME_API UClass* StaticClass<AVanishGameStateButton>()
	{
		return AVanishGameStateButton::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AVanishGameStateButton(Z_Construct_UClass_AVanishGameStateButton, &AVanishGameStateButton::StaticClass, TEXT("/Script/Monochrome"), TEXT("AVanishGameStateButton"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVanishGameStateButton);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
