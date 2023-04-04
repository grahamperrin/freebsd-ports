# nvidia-drm.ko Kernel module port
#
# This comes from the following repo:
# https://github.com/amshafer/nvidia-driver

PORTNAME=	nvidia-510-drm-kmod
PORTVERSION=	${NVIDIA_DISTVERSION}
CATEGORIES=	graphics kld

MAINTAINER=	ashafer@badland.io
COMMENT=	NVIDIA DRM Kernel Module
WWW=		https://github.com/amshafer/nvidia-driver

ONLY_FOR_ARCHS=	amd64
USES=		kmod

RUN_DEPENDS=	${KMODDIR}/drm.ko:graphics/drm-510-kmod \
	${KMODDIR}/nvidia.ko:x11/nvidia-driver

.include "${.CURDIR}/../drm-510-kmod/Makefile.version"
.include "${.CURDIR}/../../x11/nvidia-driver/Makefile.version"

LICENSE_FILE=	${WRKSRC}/nvidia/doc/license.txt

NVIDIA_GH_TAGNAME=	${PORTNAME}-${PORTVERSION}
USE_GITHUB=	yes
GH_ACCOUNT=	amshafer freebsd:drm
GH_PROJECT=	nvidia-driver drm-kmod:drm
GH_TAGNAME:=	${NVIDIA_GH_TAGNAME} ${DRM_KMOD_GH_TAGNAME}:drm

PLIST_FILES=	boot/modules/nvidia-drm.ko

MAKE_ENV+=	DRMKMODDIR=${WRKDIR}/drm-kmod-${DRM_KMOD_GH_TAGNAME}/

do-build:
	${MAKE_ENV} ${MAKE} -C ${WRKDIR}/nvidia-driver-${NVIDIA_GH_TAGNAME}/nvidia/src/nvidia-drm/

do-install:
	${MAKE_ENV} ${MAKE} install -C ${WRKDIR}/nvidia-driver-${NVIDIA_GH_TAGNAME}/nvidia/src/nvidia-drm/

.include <bsd.port.mk>
