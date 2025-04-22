#pragma once


namespace Engine
{
	class Drawable
	{
	public:
		Drawable()=default;
		virtual void Draw() const=0;
		virtual ~Drawable()=default;
	
	};
}