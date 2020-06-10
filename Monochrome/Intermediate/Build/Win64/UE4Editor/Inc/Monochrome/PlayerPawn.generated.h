// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MONOCHROME_PlayerPawn_generated_h
#error "PlayerPawn.generated.h already included, missing '#pragma once' in PlayerPawn.h"
#endif
#define MONOCHROME_PlayerPawn_generated_h

#define Monochrome_Source_Monochrome_PlayerPawn_h_12_SPARSE_DATA
#define Monochrome_Source_Monochrome_PlayerPawn_h_12_RPC_WRAPPERS
#define Monochrome_Source_Monochrome_PlayerPawn_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define Monochrome_Source_Monochrome_PlayerPawn_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPlayerPawn(); \
	friend struct Z_Construct_UClass_APlayerPawn_Statics; \
public: \
	DECLARE_CLASS(APlayerPawn, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Monochrome"), NO_API) \
	DECLARE_SERIALIZER(APlayerPawn)


#define Monochrome_Source_Monochrome_PlayerPawn_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAPlayerPawn(); \
	friend struct Z_Construct_UClass_APlayerPawn_Statics; \
public: \
	DECLARE_CLASS(APlayerPawn, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Monochrome"), NO_API) \
	DECLARE_SERIALIZER(APlayerPawn)


#define Monochrome_Source_Monochrome_PlayerPawn_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APlayerPawn(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APlayerPawn) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlayerPawn); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlayerPawn); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APlayerPawn(APlayerPawn&&); \
	NO_API APlayerPawn(const APlayerPawn&); \
public:


#define Monochrome_Source_Monochrome_PlayerPawn_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APlayerPawn(APlayerPawn&&); \
	NO_API APlayerPawn(const APlayerPawn&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlayerPawn); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlayerPawn); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APlayerPawn)


#define Monochrome_Source_Monochrome_PlayerPawn_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__m_CapsuleComponent() { return STRUCT_OFFSET(APlayerPawn, m_CapsuleComponent); } \
	FORCEINLINE static uint32 __PPO__m_SpriteComponent() { return STRUCT_OFFSET(APlayerPawn, m_SpriteComponent); } \
	FORCEINLINE static uint32 __PPO__m_SpringArm() { return STRUCT_OFFSET(APlayerPawn, m_SpringArm); } \
	FORCEINLINE static uint32 __PPO__m_CameraComponent() { return STRUCT_OFFSET(APlayerPawn, m_CameraComponent); } \
	FORCEINLINE static uint32 __PPO__m_MoveSpeed() { return STRUCT_OFFSET(APlayerPawn, m_MoveSpeed); }


#define Monochrome_Source_Monochrome_PlayerPawn_h_9_PROLOG
#define Monochrome_Source_Monochrome_PlayerPawn_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Monochrome_Source_Monochrome_PlayerPawn_h_12_PRIVATE_PROPERTY_OFFSET \
	Monochrome_Source_Monochrome_PlayerPawn_h_12_SPARSE_DATA \
	Monochrome_Source_Monochrome_PlayerPawn_h_12_RPC_WRAPPERS \
	Monochrome_Source_Monochrome_PlayerPawn_h_12_INCLASS \
	Monochrome_Source_Monochrome_PlayerPawn_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Monochrome_Source_Monochrome_PlayerPawn_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Monochrome_Source_Monochrome_PlayerPawn_h_12_PRIVATE_PROPERTY_OFFSET \
	Monochrome_Source_Monochrome_PlayerPawn_h_12_SPARSE_DATA \
	Monochrome_Source_Monochrome_PlayerPawn_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	Monochrome_Source_Monochrome_PlayerPawn_h_12_INCLASS_NO_PURE_DECLS \
	Monochrome_Source_Monochrome_PlayerPawn_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MONOCHROME_API UClass* StaticClass<class APlayerPawn>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Monochrome_Source_Monochrome_PlayerPawn_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
