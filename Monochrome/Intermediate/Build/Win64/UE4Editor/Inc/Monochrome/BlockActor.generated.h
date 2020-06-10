// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MONOCHROME_BlockActor_generated_h
#error "BlockActor.generated.h already included, missing '#pragma once' in BlockActor.h"
#endif
#define MONOCHROME_BlockActor_generated_h

#define Monochrome_Source_Monochrome_BlockActor_h_20_SPARSE_DATA
#define Monochrome_Source_Monochrome_BlockActor_h_20_RPC_WRAPPERS
#define Monochrome_Source_Monochrome_BlockActor_h_20_RPC_WRAPPERS_NO_PURE_DECLS
#define Monochrome_Source_Monochrome_BlockActor_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABlockActor(); \
	friend struct Z_Construct_UClass_ABlockActor_Statics; \
public: \
	DECLARE_CLASS(ABlockActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Monochrome"), NO_API) \
	DECLARE_SERIALIZER(ABlockActor)


#define Monochrome_Source_Monochrome_BlockActor_h_20_INCLASS \
private: \
	static void StaticRegisterNativesABlockActor(); \
	friend struct Z_Construct_UClass_ABlockActor_Statics; \
public: \
	DECLARE_CLASS(ABlockActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Monochrome"), NO_API) \
	DECLARE_SERIALIZER(ABlockActor)


#define Monochrome_Source_Monochrome_BlockActor_h_20_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ABlockActor(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ABlockActor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABlockActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABlockActor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABlockActor(ABlockActor&&); \
	NO_API ABlockActor(const ABlockActor&); \
public:


#define Monochrome_Source_Monochrome_BlockActor_h_20_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABlockActor(ABlockActor&&); \
	NO_API ABlockActor(const ABlockActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABlockActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABlockActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABlockActor)


#define Monochrome_Source_Monochrome_BlockActor_h_20_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__m_BlockColor() { return STRUCT_OFFSET(ABlockActor, m_BlockColor); } \
	FORCEINLINE static uint32 __PPO__m_BoxComponent() { return STRUCT_OFFSET(ABlockActor, m_BoxComponent); } \
	FORCEINLINE static uint32 __PPO__m_SpriteComponent() { return STRUCT_OFFSET(ABlockActor, m_SpriteComponent); }


#define Monochrome_Source_Monochrome_BlockActor_h_17_PROLOG
#define Monochrome_Source_Monochrome_BlockActor_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Monochrome_Source_Monochrome_BlockActor_h_20_PRIVATE_PROPERTY_OFFSET \
	Monochrome_Source_Monochrome_BlockActor_h_20_SPARSE_DATA \
	Monochrome_Source_Monochrome_BlockActor_h_20_RPC_WRAPPERS \
	Monochrome_Source_Monochrome_BlockActor_h_20_INCLASS \
	Monochrome_Source_Monochrome_BlockActor_h_20_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Monochrome_Source_Monochrome_BlockActor_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Monochrome_Source_Monochrome_BlockActor_h_20_PRIVATE_PROPERTY_OFFSET \
	Monochrome_Source_Monochrome_BlockActor_h_20_SPARSE_DATA \
	Monochrome_Source_Monochrome_BlockActor_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	Monochrome_Source_Monochrome_BlockActor_h_20_INCLASS_NO_PURE_DECLS \
	Monochrome_Source_Monochrome_BlockActor_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MONOCHROME_API UClass* StaticClass<class ABlockActor>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Monochrome_Source_Monochrome_BlockActor_h


#define FOREACH_ENUM_BLOCKCOLOR(op) \
	op(BlockBlack) \
	op(BlockWhite) \
	op(BlockNeutral) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
