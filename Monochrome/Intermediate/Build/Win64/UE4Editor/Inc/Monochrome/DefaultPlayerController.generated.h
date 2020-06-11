// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MONOCHROME_DefaultPlayerController_generated_h
#error "DefaultPlayerController.generated.h already included, missing '#pragma once' in DefaultPlayerController.h"
#endif
#define MONOCHROME_DefaultPlayerController_generated_h

#define Monochrome_Source_Monochrome_DefaultPlayerController_h_15_SPARSE_DATA
#define Monochrome_Source_Monochrome_DefaultPlayerController_h_15_RPC_WRAPPERS
#define Monochrome_Source_Monochrome_DefaultPlayerController_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define Monochrome_Source_Monochrome_DefaultPlayerController_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesADefaultPlayerController(); \
	friend struct Z_Construct_UClass_ADefaultPlayerController_Statics; \
public: \
	DECLARE_CLASS(ADefaultPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Monochrome"), NO_API) \
	DECLARE_SERIALIZER(ADefaultPlayerController)


#define Monochrome_Source_Monochrome_DefaultPlayerController_h_15_INCLASS \
private: \
	static void StaticRegisterNativesADefaultPlayerController(); \
	friend struct Z_Construct_UClass_ADefaultPlayerController_Statics; \
public: \
	DECLARE_CLASS(ADefaultPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Monochrome"), NO_API) \
	DECLARE_SERIALIZER(ADefaultPlayerController)


#define Monochrome_Source_Monochrome_DefaultPlayerController_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ADefaultPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ADefaultPlayerController) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADefaultPlayerController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADefaultPlayerController); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADefaultPlayerController(ADefaultPlayerController&&); \
	NO_API ADefaultPlayerController(const ADefaultPlayerController&); \
public:


#define Monochrome_Source_Monochrome_DefaultPlayerController_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ADefaultPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADefaultPlayerController(ADefaultPlayerController&&); \
	NO_API ADefaultPlayerController(const ADefaultPlayerController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADefaultPlayerController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADefaultPlayerController); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ADefaultPlayerController)


#define Monochrome_Source_Monochrome_DefaultPlayerController_h_15_PRIVATE_PROPERTY_OFFSET
#define Monochrome_Source_Monochrome_DefaultPlayerController_h_12_PROLOG
#define Monochrome_Source_Monochrome_DefaultPlayerController_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Monochrome_Source_Monochrome_DefaultPlayerController_h_15_PRIVATE_PROPERTY_OFFSET \
	Monochrome_Source_Monochrome_DefaultPlayerController_h_15_SPARSE_DATA \
	Monochrome_Source_Monochrome_DefaultPlayerController_h_15_RPC_WRAPPERS \
	Monochrome_Source_Monochrome_DefaultPlayerController_h_15_INCLASS \
	Monochrome_Source_Monochrome_DefaultPlayerController_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Monochrome_Source_Monochrome_DefaultPlayerController_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Monochrome_Source_Monochrome_DefaultPlayerController_h_15_PRIVATE_PROPERTY_OFFSET \
	Monochrome_Source_Monochrome_DefaultPlayerController_h_15_SPARSE_DATA \
	Monochrome_Source_Monochrome_DefaultPlayerController_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	Monochrome_Source_Monochrome_DefaultPlayerController_h_15_INCLASS_NO_PURE_DECLS \
	Monochrome_Source_Monochrome_DefaultPlayerController_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MONOCHROME_API UClass* StaticClass<class ADefaultPlayerController>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Monochrome_Source_Monochrome_DefaultPlayerController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
