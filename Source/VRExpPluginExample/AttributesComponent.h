// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AttributesComponent.generated.h"


USTRUCT(BlueprintType)
struct FAttribute
{
	GENERATED_BODY()


	/** Name of attribute */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes")
	FName Name;

	/** BaseValue is the starting value. Should be used to apply modifiers such as increasing max health */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes")
	float BaseValue = 100.f;

	/** Max Value derived from BaseValue with any modifiers applied */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes")
	float MaxValue = 100.f;

	/** Current value which should be used to perform calculations and actions badsed on it */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes")
	float CurrentValue = 0.f;

	/** Is the attribute clamped to zero ? Check is here in the case of an attribute that can go below 0.f */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes")
	bool bClampToZero = true;
};

USTRUCT(BlueprintType)
struct FAttributeChangeResult
{
	GENERATED_BODY()

	FAttributeChangeResult() = default;
	FAttributeChangeResult(bool bInSuccess, const FString& InReason) : bSuccess(bInSuccess), FailReason(InReason) {}

	static FAttributeChangeResult MakeFailed(const FString& Reason)
	{
		return FAttributeChangeResult(false, Reason);
	}

	static FAttributeChangeResult MakeSuccessful()
	{
		return FAttributeChangeResult(true, FString());
	}

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	bool bSuccess;

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FString FailReason;
};


DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnAttributeChanged, const FAttribute&, ChangedAttribute, float, OldValue, float, Delta, AActor*, HitInstigator);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VREXPPLUGINEXAMPLE_API UAttributesComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAttributesComponent();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Attributes")
	static UAttributesComponent* GetAttributesComponent(const AActor* FromActor);

	UFUNCTION(BlueprintCallable, Category="Attributes")
	FAttributeChangeResult HealActor(AActor* HitInstigator, float Value);

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	FAttributeChangeResult DamageActor(AActor* HitInstigator, float Value);

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	FAttributeChangeResult ApplyHealthDelta(AActor* HitInstigator, float Value);

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	bool CheckIfAttackHit(int rollResult);

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	static void SetAttributeValue(UPARAM(ref)FAttribute& Attribute, int NewValue);

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	static float GetAttributeMax(UPARAM(ref)FAttribute& Attribute);

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(BlueprintAssignable, Category = "Attributes")
	FOnAttributeChanged OnHealthAttributeChanged;

	const FAttribute& GetArmorAttribute() const;

	const FAttribute& GetHealthAttribute() const;

	const FAttribute& GetConstitutionAttribute() const;
	const FAttribute& GetDexterityAttribute() const;
	const FAttribute& GetCharismaAttribute() const;
	const FAttribute& GetStrengthAttribute() const;
	const FAttribute& GetWisdomAttribute() const;
	const FAttribute& GetIntelligenceAttribute() const;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Replicated, Category="Attributes")
	FAttribute HealthAttribute;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Replicated, Category="Attributes")
	FAttribute ArmorAttribute;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Replicated, Category="Attributes")
	FAttribute StrengthAttribute;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Replicated, Category="Attributes")
	FAttribute DexterityAttribute;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Replicated, Category="Attributes")
	FAttribute ConstitutionAttribute;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Replicated, Category="Attributes")
	FAttribute CharismaAttribute;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Replicated, Category="Attributes")
	FAttribute IntelligenceAttribute;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Replicated, Category="Attributes")
	FAttribute WisdomAttribute;
		
};
