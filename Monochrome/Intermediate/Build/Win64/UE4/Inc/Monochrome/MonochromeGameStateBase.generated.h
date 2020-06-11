// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MONOCHROME_MonochromeGameStateBase_generated_h
#error "MonochromeGameStateBase.generated.h already included, missing '#pragma once' in MonochromeGameStateBase.h"
#endif
#define MONOCHROME_MonochromeGameStateBase_generated_h

#define Monochrome_Source_Monochrome_MonochromeGameStateBase_h_22_SPARSE_DATA
#define Monochrome_Source_Monochrome_MonochromeGameStateBase_h_22_RPC_WRAPPERS
#define Monochrome_Source_Monochrome_MonochromeGameStateBase_h_22_RPC_WRAPPERS_NO_PURE_DECLS
#define Monochrome_Source_Monochrome_MonochromeGameStateBase_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMonochromeGameStateBase(); \
	friend struct Z_Construct_UClass_AMonochromeGameStateBase_Statics; \
public: \
	DECLARE_CLASS(AMonochromeGameStateBase, AGameStateBase, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Monochrome"), NO_API) \
	DECLARE_SERIALIZER(AMonochromeGameStateBase)


#define Monochrome_Source_Monochrome_MonochromeGameStateBase_h_22_INCLASS \
private: \
	static void StaticRegisterNativesAMonochromeGameStateBase(); \
	friend struct Z_Construct_UClass_AMonochromeGameStateBase_Statics; \
public: \
	DECLARE_CLASS(AMonochromeGameStateBase, AGameStateBase, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Monochrome"), NO_API) \
	DECLARE_SERIALIZER(AMonochromeGameStateBase)


#define Monochrome_Source_Monochrome_MonochromeGameStateBase_h_22_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMonochromeGameStateBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMonochromeGameStateBase) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMonochromeGameStateBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMonochromeGameStateBase); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMonochromeGameStateBase(AMonochromeGameStateBase&&); \
	NO_API AMonochromeGameStateBase(const AMonochromeGameStateBase&); \
public:


#define Monochrome_Source_Monochrome_MonochromeGameStateBase_h_22_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMonochromeGameStateBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMonochromeGameStateBase(AMonochromeGameStateBase&&); \
	NO_API AMonochromeGameStateBase(const AMonochromeGameStateBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMonochromeGameStateBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMonochromeGameStateBase); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMonochromeGameStateBase)


#define Monochrome_Source_Monochrome_MonochromeGameStateBase_h_22_PRIVATE_PROPERTY_OFFSET
#define Monochrome_Source_Monochrome_MonochromeGameStateBase_h_19_PROLOG
#define Monochrome_Source_Monochrome_MonochromeGameStateBase_h_22_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Monochrome_Source_Monochrome_MonochromeGameStateBase_h_22_PRIVATE_PROPERTY_OFFSET \
	Monochrome_Source_Monochrome_MonochromeGameStateBase_h_22_SPARSE_DATA \
	Monochrome_Source_Monochrome_MonochromeGameStateBase_h_22_RPC_WRAPPERS \
	Monochrome_Source_Monochrome_MonochromeGameStateBase_h_22_INCLASS \
	Monochrome_Source_Monochrome_MonochromeGameStateBase_h_22_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Monochrome_Source_Monochrome_MonochromeGameStateBase_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Monochrome_Source_Monochrome_MonochromeGameStateBase_h_22_PRIVATE_PROPERTY_OFFSET \
	Monochrome_Source_Monochrome_MonochromeGameStateBase_h_22_SPARSE_DATA \
	Monochrome_Source_Monochrome_MonochromeGameStateBase_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	Monochrome_Source_Monochrome_MonochromeGameStateBase_h_22_INCLASS_NO_PURE_DECLS \
	Monochrome_Source_Monochrome_MonochromeGameStateBase_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MONOCHROME_API UClass* StaticClass<class AMonochromeGameStateBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Monochrome_Source_Monochrome_MonochromeGameStateBase_h


#define FOREACH_ENUM_GAMECOLORSTATE(op) \
	op(GameStateBlack) \
	op(GameStateWhite) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
