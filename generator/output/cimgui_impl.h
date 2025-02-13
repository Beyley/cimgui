#ifdef CIMGUI_USE_SDL2

typedef struct SDL_Window SDL_Window;
typedef struct SDL_Renderer SDL_Renderer;
struct SDL_Window;
struct SDL_Renderer;
typedef union SDL_Event SDL_Event;CIMGUI_API bool ImGui_ImplSDL2_InitForOpenGL(SDL_Window* window,void* sdl_gl_context);
CIMGUI_API bool ImGui_ImplSDL2_InitForVulkan(SDL_Window* window);
CIMGUI_API bool ImGui_ImplSDL2_InitForD3D(SDL_Window* window);
CIMGUI_API bool ImGui_ImplSDL2_InitForMetal(SDL_Window* window);
CIMGUI_API bool ImGui_ImplSDL2_InitForSDLRenderer(SDL_Window* window,SDL_Renderer* renderer);
CIMGUI_API void ImGui_ImplSDL2_Shutdown(void);
CIMGUI_API void ImGui_ImplSDL2_NewFrame(void);
CIMGUI_API bool ImGui_ImplSDL2_ProcessEvent(const SDL_Event* event);

#endif
#ifdef CIMGUI_USE_WGPU
CIMGUI_API _Bool ImGui_ImplWGPU_Init(WGPUDevice device,int num_frames_in_flight,WGPUTextureFormat rt_format,WGPUTextureFormat depth_format);
CIMGUI_API void ImGui_ImplWGPU_Shutdown(void);
CIMGUI_API void ImGui_ImplWGPU_NewFrame(void);
CIMGUI_API void ImGui_ImplWGPU_RenderDrawData(ImDrawData* draw_data,WGPURenderPassEncoder pass_encoder);
CIMGUI_API void ImGui_ImplWGPU_InvalidateDeviceObjects(void);
CIMGUI_API _Bool ImGui_ImplWGPU_CreateDeviceObjects(void);

#endif
