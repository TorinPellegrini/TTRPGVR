// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributesComponent.h"
#include "VRExpPluginExample.h"
#include "Net/UnrealNetwork.h"


// Called when the game starts
void UAttributesComponent::BeginPlay()
{
	Super::BeginPlay();

	HealthAttribute.MaxValue = HealthAttribute.BaseValue;
	HealthAttribute.CurrentValue = HealthAttribute.BaseValue;

}

// Sets default values for this component's properties
UAttributesComponent::UAttributesComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

UAttributesComponent* UAttributesComponent::GetAttributesComponent(const AActor* FromActor)
{
	return FromActor->GetComponentByClass<UAttributesComponent>();
}

FAttributeChangeResult UAttributesComponent::HealActor(AActor* HitInstigator, float Value)
{
	if (Value < 0)
	{
		UE_LOG(TTRPGLog, Warning, TEXT("Trying to heal the player with a negative value inside HealPlayer FUNCTION, %.2f! Ignoring heal command."), Value);
		return FAttributeChangeResult::MakeFailed(FString("Can not heal with a negative amount!"));
	}

	return ApplyHealthDelta(HitInstigator, Value);
}


FAttributeChangeResult UAttributesComponent::DamageActor(AActor* HitInstigator, float Value)
{
	if (Value < 0)
	{
		UE_LOG(TTRPGLog, Warning, TEXT("Trying to damage player with a negative value inside DamagePlayer FUNCTION, %.2f! Converting value to a positive number."), Value);
		Value = FMath::Abs(Value);
	}

	return ApplyHealthDelta(HitInstigator, -Value);
}

FAttributeChangeResult UAttributesComponent::ApplyHealthDelta(AActor* HitInstigator, float Value)
{
	const float OldValue = HealthAttribute.CurrentValue;

	/** Validate Health Change Rules */
	if (Value > 0.f && HealthAttribute.CurrentValue >= HealthAttribute.MaxValue)
	{
		return FAttributeChangeResult::MakeFailed(FString("Health is already at max"));
	}
	if (Value < 0.f && FMath::IsNearlyZero(HealthAttribute.CurrentValue) && HealthAttribute.bClampToZero)
	{
		return FAttributeChangeResult::MakeFailed(FString("Health is already at 0"));
	}

	HealthAttribute.CurrentValue += Value;
	HealthAttribute.CurrentValue = FMath::Min(HealthAttribute.CurrentValue, HealthAttribute.MaxValue);

	if (HealthAttribute.bClampToZero)
	{
		HealthAttribute.CurrentValue = FMath::Max(HealthAttribute.CurrentValue, 0.0f);
	}

	const float AppliedDelta = (HealthAttribute.CurrentValue - OldValue);

	// Only call the delegate if an actual change to the health has happened
	if (AppliedDelta != 0.f)
	{
		OnHealthAttributeChanged.Broadcast(HealthAttribute, OldValue, AppliedDelta, HitInstigator);
		return FAttributeChangeResult::MakeSuccessful();
	}

	return FAttributeChangeResult::MakeFailed(FString("Unknown Reason"));
}

bool UAttributesComponent::CheckIfAttackHit(int rollResult)
{
	int armorClass = ArmorAttribute.CurrentValue;
	if(rollResult < armorClass)
	{
		return false;
	}
	if(rollResult >= armorClass)
	{
		return true;
	}

	return false;
}

void UAttributesComponent::SetAttributeValue(FAttribute& Attribute, int NewValue)
{
	Attribute.BaseValue = NewValue;
	Attribute.MaxValue = NewValue;
	Attribute.CurrentValue = NewValue;
}

float UAttributesComponent::GetAttributeMax(FAttribute& Attribute)
{
	return Attribute.MaxValue;
}

void UAttributesComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ThisClass, HealthAttribute);
	DOREPLIFETIME(ThisClass, ArmorAttribute);
	DOREPLIFETIME(ThisClass, StrengthAttribute);
	DOREPLIFETIME(ThisClass, DexterityAttribute);
	DOREPLIFETIME(ThisClass, ConstitutionAttribute);
	DOREPLIFETIME(ThisClass, CharismaAttribute);
	DOREPLIFETIME(ThisClass, IntelligenceAttribute);
	DOREPLIFETIME(ThisClass, WisdomAttribute);
}

const FAttribute& UAttributesComponent::GetHealthAttribute() const
{
	return HealthAttribute;
}

const FAttribute& UAttributesComponent::GetConstitutionAttribute() const
{
	return ConstitutionAttribute;
}

const FAttribute& UAttributesComponent::GetDexterityAttribute() const
{
	return DexterityAttribute;
}

const FAttribute& UAttributesComponent::GetCharismaAttribute() const
{
	return CharismaAttribute;
}

const FAttribute& UAttributesComponent::GetStrengthAttribute() const
{
	return StrengthAttribute;
}

const FAttribute& UAttributesComponent::GetWisdomAttribute() const
{
	return WisdomAttribute;
}

const FAttribute& UAttributesComponent::GetIntelligenceAttribute() const
{
	return IntelligenceAttribute;
}

const FAttribute& UAttributesComponent::GetArmorAttribute() const
{
	return ArmorAttribute;
}



