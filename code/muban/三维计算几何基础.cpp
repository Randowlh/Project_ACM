#define triple(x, y, z) ((x) * ((y) ^ (z)))

struct vec3 {
	double x, y, z;
	vec3 (double x0 = 0, double y0 = 0, double z0 = 0) : x(x0), y(y0), z(z0) {}
	vec3 * read() {scanf("%lf%lf%lf", &x, &y, &z); return this;}
	inline vec3 operator - () const {return vec3(-x, -y, -z);}
	inline vec3 operator + (const vec3 &B) const {return vec3(x + B.x, y + B.y, z + B.z);}
	inline vec3 operator - (const vec3 &B) const {return vec3(x - B.x, y - B.y, z - B.z);}
	inline vec3 operator * (double k) const {return vec3(x * k, y * k);}
	inline vec3 operator / (double k) const {return *this * (1.0 / k);}
	inline double operator * (const vec3 &B) const {return x * B.x + y * B.y + z * B.z;}
	inline vec3 operator ^ (const vec3 &B) const {return vec3(y * B.z - z * B.y, z * B.x - x * B.z, x * B.y - y * B.x);}
	inline double norm2() const {return x * x + y * y + z * z;}
	inline double norm() const {return sqrt(x * x + y * y + z * z);}
	inline bool operator < (const vec3 &B) const {return lt(x, B.x) || le(x, B.x) && (lt(y, B.y) || le(y, B.y) && lt(z, B.z));}
	inline bool operator == (const vec3 &B) const {return eq(x, B.x) && eq(y, B.y) && eq(z, B.z);}
};

// Positive if Right-hand rule
inline double volume(const vec3 A, const vec3 B, const vec3 C, const vec3 D) {return triple(B - A, C - A, D - A);}

struct line3 {
	vec3 P, t;
	line3 (vec3 _P = vec3(), vec3 _t = vec3()) : P(_P), t(_t) {}
};

inline double dis2(const vec3 P, const line3 l) {return ((P - l.P) ^ l.t).norm2() / l.t.norm2();}

struct plane {
	double A, B, C, D; // Ax + By + Cz + D = 0
	plane (double A0 = 0.0, double B0 = 0.0, double C0 = 0.0, double D0 = 0.0) : A(A0), B(B0), C(C0), D(D0) {}
	plane (const vec3 &u, const vec3 &v, const vec3 &w) {vec3 t = (v - u) ^ (w - u); A = t.x, B = t.y, C = t.z, D = -triple(u, v, w);} // > 0 if it follows Right-hand rule
	inline vec3 normVec() const {return vec3(A, B, C);}
	inline double norm2() const {return A * A + B * B + C * C;}
	inline double operator () (const vec3 &P) const {return A * P.x + B * P.y + C * P.z + D;}
};

inline double dis2(const vec3 P, const plane F) {return F(P) * F(P) / F.norm2();}