#pragma once


namespace Engine
{
	class Drawable
	{
	private:
	public:
		Drawable();
		virtual void Draw() const;
		virtual ~Drawable();
	
	};
}