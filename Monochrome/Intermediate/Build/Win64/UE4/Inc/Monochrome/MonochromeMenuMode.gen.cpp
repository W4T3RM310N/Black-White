// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Monochrome/MonochromeMenuMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMonochromeMenuMode() {}
// Cross Module References
	MONOCHROME_API UClass* Z_Construct_UClass_AMonochromeMenuMode_NoRegister();
	MONOCHROME_API UClass* Z_Construct_UClass_AMonochromeMenuMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_Monochrome();
// End Cross Module References
	void AMonochromeMenuMode::StaticRegisterNativesAMonochromeMenuMode()
	{
	}
	UClass* Z_Construct_UClass_AMonochromeMenuMode_NoRegister()
	{
		return AMonochromeMenuMode::StaticClass();
	}
	struct Z_Construct_UClass_AMonochromeMenuMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMonochromeMenuMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_Monochrome,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMonochromeMenuMode_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "MonochromeMenuMode.h" },
		{ "ModuleRelativePath", "MonochromeMenuMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMonochromeMenuMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMonochromeMenuMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMonochromeMenuMode_Statics::ClassParams = {
		&AMonochromeMenuMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AMonochromeMenuMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMonochromeMenuMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMonochromeMenuMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMonochromeMenuMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMonochromeMenuMode, 138517017);
	template<> MONOCHROME_API UClass* StaticClass<AMonochromeMenuMode>()
	{
		return AMonochromeMenuMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMonochromeMenuMode(Z_Construct_UClass_AMonochromeMenuMode, &AMonochromeMenuMode::StaticClass, TEXT("/Script/Monochrome"), TEXT("AMonochromeMenuMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMonochromeMenuMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
