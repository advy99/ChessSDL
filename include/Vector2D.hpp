#ifndef VECTOR2D_H_INCLUDED
#define VECTOR2D_H_INCLUDED


class Vector2D {
	private:
		int x_;
		int y_;

	public:
		Vector2D();
		Vector2D(const int X, const int Y);

		double length() const;


		int get_x() const;
		int get_y() const;

		void set_x(const int new_x);
		void set_y(const int new_y);

		Vector2D operator + (const Vector2D & other) const;
		Vector2D & operator += (const Vector2D & other);

		Vector2D operator - (const Vector2D & other) const ;
		Vector2D & operator -= (const Vector2D & other);


		Vector2D operator / (const double scalar) const ;
		Vector2D & operator /= (const double scalar);

		friend Vector2D operator * (const Vector2D & vector, const double scalar);
		friend Vector2D operator * (const double scalar, const Vector2D & vector);

		Vector2D & operator *= (const double scalar);

		void normalize();
};


#endif
