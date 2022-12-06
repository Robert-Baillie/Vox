#pragma once


namespace Vox {

	/// Interface for Component Type
	class IComponentType 
	{
	public:
		virtual int GetComponentTypeID() { return ID; };

	private:
		int ID;
	};


	/// ComponentType<T> - holds the type of a component so that the ID for type can be called back
	template <typename T>
	class ComponentType : IComponentType
	{
		
	};
}