#ifndef LAYER_H_INCLUDED
#define LAYER_H_INCLUDED

class Layer {
	private:

	public:
		virtual ~Layer() {};
		virtual void render() = 0;
		virtual void update() = 0;

};


#endif
