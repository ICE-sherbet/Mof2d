#pragma once
class Object
{
public:
	virtual ~Object() = default;
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
};

