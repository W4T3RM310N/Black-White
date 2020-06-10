// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FHitResult;
struct FVector;
#ifdef MONOCHROME_GameStateButtonBase_generated_h
#error "GameStateButtonBase.generated.h already included, missing '#pragma once' in GameStateButtonBase.h"
#endif
#define MONOCHROME_GameStateButtonBase_generated_h

#define Monochrome_Source_Monochrome_GameStateButtonBase_h_12_SPARSE_DATA
#define Monochrome_Source_Monochrome_GameStateButtonBase_h_12_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnOverlapEnd) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnOverlapEnd(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnOverlapBegin) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnOverlapBegin(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnHit(Z_Param_HitComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalImpulse,Z_Param_Out_Hit); \
		P_NATIVE_END; \
	}


#define Monochrome_Source_Monochrome_GameStateButtonBase_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnOverlapEnd) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnOverlapEnd(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnOverlapBegin) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnOverlapBegin(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnHit(Z_Param_HitComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalImpulse,Z_Param_Out_Hit); \
		P_NATIVE_END; \
	}


#define Monochrome_Source_Monochrome_GameStateButtonBase_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGameStateButtonBase(); \
	friend struct Z_Construct_UClass_AGameStateButtonBase_Statics; \
public: \
	DECLARE_CLASS(AGameStateButtonBase, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Monochrome"), NO_API) \
	DECLARE_SERIALIZER(AGameStateButtonBase)


#define Monochrome_Source_Monochrome_GameStateButtonBase_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAGameStateButtonBase(); \
	friend struct Z_Construct_UClass_AGameStateButtonBase_Statics; \
public: \
	DECLARE_CLASS(AGameStateButtonBase, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Monochrome"), NO_API) \
	DECLARE_SERIALIZER(AGameStateButtonBase)


#define Monochrome_Source_Monochrome_GameStateButtonBase_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGameStateButtonBase(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGameStateButtonBase) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGameStateButtonBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGameStateButtonBase); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGameStateButtonBase(AGameStateButtonBase&&); \
	NO_API AGameStateButtonBase(const AGameStateButtonBase&); \
public:


#define Monochrome_Source_Monochrome_GameStateButtonBase_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGameStateButtonBase(AGameStateButtonBase&&); \
	NO_API AGameStateButtonBase(const AGameStateButtonBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGameStateButtonBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGameStateButtonBase); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGameStateButtonBase)


#define Monochrome_Source_Monochrome_GameStateButtonBase_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__m_SpriteComponent() { return STRUCT_OFFSET(AGameStateButtonBase, m_SpriteComponent); } \
	FORCEINLINE static uint32 __PPO__m_BoxComponent() { return STRUCT_OFFSET(AGameStateButtonBase, m_BoxComponent); } \
	FORCEINLINE static uint32 __PPO__m_TriggerComponent() { return STRUCT_OFFSET(AGameStateButtonBase, m_TriggerComponent); }


#define Monochrome_Source_Monochrome_GameStateButtonBase_h_9_PROLOG
#define Monochrome_Source_Monochrome_GameStateButtonBase_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Monochrome_Source_Monochrome_GameStateButtonBase_h_12_PRIVATE_PROPERTY_OFFSET \
	Monochrome_Source_Monochrome_GameStateButtonBase_h_12_SPARSE_DATA \
	Monochrome_Source_Monochrome_GameStateButtonBase_h_12_RPC_WRAPPERS \
	Monochrome_Source_Monochrome_GameStateButtonBase_h_12_INCLASS \
	Monochrome_Source_Monochrome_GameStateButtonBase_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Monochrome_Source_Monochrome_GameStateButtonBase_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Monochrome_Source_Monochrome_GameStateButtonBase_h_12_PRIVATE_PROPERTY_OFFSET \
	Monochrome_Source_Monochrome_GameStateButtonBase_h_12_SPARSE_DATA \
	Monochrome_Source_Monochrome_GameStateButtonBase_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	Monochrome_Source_Monochrome_GameStateButtonBase_h_12_INCLASS_NO_PURE_DECLS \
	Monochrome_Source_Monochrome_GameStateButtonBase_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MONOCHROME_API UClass* StaticClass<class AGameStateButtonBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Monochrome_Source_Monochrome_GameStateButtonBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
