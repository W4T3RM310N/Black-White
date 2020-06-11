// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Monochrome/BlockActor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBlockActor() {}
// Cross Module References
	MONOCHROME_API UEnum* Z_Construct_UEnum_Monochrome_BlockColor();
	UPackage* Z_Construct_UPackage__Script_Monochrome();
	MONOCHROME_API UClass* Z_Construct_UClass_ABlockActor_NoRegister();
	MONOCHROME_API UClass* Z_Construct_UClass_ABlockActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	PAPER2D_API UClass* Z_Construct_UClass_UPaperSpriteComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
// End Cross Module References
	static UEnum* BlockColor_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_Monochrome_BlockColor, Z_Construct_UPackage__Script_Monochrome(), TEXT("BlockColor"));
		}
		return Singleton;
	}
	template<> MONOCHROME_API UEnum* StaticEnum<BlockColor>()
	{
		return BlockColor_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_BlockColor(BlockColor_StaticEnum, TEXT("/Script/Monochrome"), TEXT("BlockColor"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_Monochrome_BlockColor_Hash() { return 4272369897U; }
	UEnum* Z_Construct_UEnum_Monochrome_BlockColor()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_Monochrome();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("BlockColor"), 0, Get_Z_Construct_UEnum_Monochrome_BlockColor_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "BlockBlack", (int64)BlockBlack },
				{ "BlockWhite", (int64)BlockWhite },
				{ "BlockNeutral", (int64)BlockNeutral },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlockBlack.Name", "BlockBlack" },
				{ "BlockNeutral.Name", "BlockNeutral" },
				{ "BlockWhite.Name", "BlockWhite" },
				{ "ModuleRelativePath", "BlockActor.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_Monochrome,
				nullptr,
				"BlockColor",
				"BlockColor",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::Regular,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	void ABlockActor::StaticRegisterNativesABlockActor()
	{
	}
	UClass* Z_Construct_UClass_ABlockActor_NoRegister()
	{
		return ABlockActor::StaticClass();
	}
	struct Z_Construct_UClass_ABlockActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_SpriteComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_m_SpriteComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_BoxComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_m_BoxComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_BlockColor_MetaData[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_m_BlockColor;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABlockActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Monochrome,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABlockActor_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "BlockActor.h" },
		{ "ModuleRelativePath", "BlockActor.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABlockActor_Statics::NewProp_m_SpriteComponent_MetaData[] = {
		{ "Category", "Block" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "BlockActor.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABlockActor_Statics::NewProp_m_SpriteComponent = { "m_SpriteComponent", nullptr, (EPropertyFlags)0x0020080000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABlockActor, m_SpriteComponent), Z_Construct_UClass_UPaperSpriteComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABlockActor_Statics::NewProp_m_SpriteComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABlockActor_Statics::NewProp_m_SpriteComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABlockActor_Statics::NewProp_m_BoxComponent_MetaData[] = {
		{ "Category", "Block" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "BlockActor.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABlockActor_Statics::NewProp_m_BoxComponent = { "m_BoxComponent", nullptr, (EPropertyFlags)0x0020080000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABlockActor, m_BoxComponent), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABlockActor_Statics::NewProp_m_BoxComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABlockActor_Statics::NewProp_m_BoxComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABlockActor_Statics::NewProp_m_BlockColor_MetaData[] = {
		{ "Category", "Block" },
		{ "ModuleRelativePath", "BlockActor.h" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_ABlockActor_Statics::NewProp_m_BlockColor = { "m_BlockColor", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABlockActor, m_BlockColor), Z_Construct_UEnum_Monochrome_BlockColor, METADATA_PARAMS(Z_Construct_UClass_ABlockActor_Statics::NewProp_m_BlockColor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABlockActor_Statics::NewProp_m_BlockColor_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABlockActor_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABlockActor_Statics::NewProp_m_SpriteComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABlockActor_Statics::NewProp_m_BoxComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABlockActor_Statics::NewProp_m_BlockColor,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABlockActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABlockActor>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ABlockActor_Statics::ClassParams = {
		&ABlockActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ABlockActor_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ABlockActor_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ABlockActor_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ABlockActor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ABlockActor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ABlockActor_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABlockActor, 2482828337);
	template<> MONOCHROME_API UClass* StaticClass<ABlockActor>()
	{
		return ABlockActor::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABlockActor(Z_Construct_UClass_ABlockActor, &ABlockActor::StaticClass, TEXT("/Script/Monochrome"), TEXT("ABlockActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABlockActor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
